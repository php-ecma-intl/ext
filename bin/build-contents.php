#!/usr/bin/env php
<?php

declare(strict_types=1);

const EXCLUDE_PATTERNS = [
    '*.clang-*',
    '*.editorconfig',
    '*.git*',
    '.readthedocs.yml',
    'bin/*',
    'build/*',
    'captainhook.json',
    'codecov.yml',
    'conventional-commits.json',
    'docker-compose.yml',
    'docs/*',
    'package.xml',
    'phpunit.xml.dist',
    'resources/*',
    'tools/*',
];

const ROLE_PATTERNS = [
    '*.c' => 'src',
    '*.cpp' => 'src',
    '*.h' => 'src',
    '*.m4' => 'src',
    '*.stub.php' => 'src',
    '*.w32' => 'src',
    'tests/*' => 'test',
    'Makefile.frag' => 'src',
];

chdir(__DIR__ . '/..');
$dir = getcwd();
$packageFile = "$dir/package.xml";

$getRelativePath = fn (SplFileInfo $file): string => str_replace("$dir/", '', $file->getRealPath());

$files = new RecursiveIteratorIterator(new RecursiveCallbackFilterIterator(
    new RecursiveDirectoryIterator($dir, FilesystemIterator::SKIP_DOTS),
    function (SplFileInfo $current) use ($getRelativePath): bool {
        $relativePath = $getRelativePath($current);

        foreach (EXCLUDE_PATTERNS as $pattern) {
            if (fnmatch($pattern, $relativePath)) {
                return false;
            }
        }

        // Exclude anything that Git ignores or does not know about.
        if (
            exec('git check-ignore ' . escapeshellarg($relativePath) . ' 2>/dev/null')
            || !exec('git ls-files --error-unmatch ' . escapeshellarg($relativePath) . ' 2>/dev/null')
        ) {
            return false;
        }

        return true;
    },
));

$contents = [];

foreach ($files as $file) {
    $relativePath = $getRelativePath($file);
    $parts = explode('/', $relativePath);
    $filename = array_pop($parts);

    $context =& $contents;
    foreach ($parts as $part) {
        if (!isset($context[$part])) {
            $context[$part] = [];
        }
        $context =& $context[$part];
    }

    $context[$filename] = $relativePath;
}

$sort = function (array $data) use (&$sort): array {
    $result = [];
    $keys = array_keys($data);
    natcasesort($keys);

    foreach ($keys as $key) {
        if (is_array($data[$key])) {
            $result[$key] = $sort($data[$key]);
        } else {
            $result[$key] = $data[$key];
        }
    }

    return $result;
};

$contents = $sort($contents);

$addContents = function (DOMDocument $document, DOMNode $node, array $data) use (&$addContents): void {
    foreach ($data as $key => $value) {
        if (is_array($value)) {
            $dir = $document->createElement('dir');
            $dir->setAttribute('name', $key);
            $node->appendChild($dir);
            $addContents($document, $dir, $value);
        } else {
            $roleValue = 'doc';
            foreach (ROLE_PATTERNS as $pattern => $role) {
                if (fnmatch($pattern, $value)) {
                    $roleValue = $role;
                }
            }

            $file = $document->createElement('file');
            $file->setAttribute('name', $key);
            $file->setAttribute('role', $roleValue);
            $node->appendChild($file);
        }
    }
};

$dom = new DOMDocument('1.0', 'utf-8');
$dom->preserveWhiteSpace = false;
$dom->formatOutput = true;

$dom->loadXML(file_get_contents($packageFile));

$packageElement = $dom->getElementsByTagName('package');
assert(count($packageElement) === 1);
$packageElement = $packageElement->item(0);

$contentsElement = $dom->getElementsByTagName('contents');
assert(count($contentsElement) === 1);
$contentsElement = $contentsElement->item(0);

$newContentsElement = $dom->createElement('contents');
$rootDirElement = $dom->createElement('dir');
$rootDirElement->setAttribute('name', '/');
$newContentsElement->appendChild($rootDirElement);

$addContents($dom, $rootDirElement, $contents);

$packageElement->replaceChild($newContentsElement, $contentsElement);

file_put_contents($packageFile, $dom->saveXML());

echo "Contents written to package.xml" . PHP_EOL;
