--TEST--
Options can set combinations of properties
--EXTENSIONS--
ecma_intl
--FILE--
<?php
declare(strict_types=1);

use Ecma\Intl\Locale\Options;

$properties = [
    'calendar' => 'gregory',
    'caseFirst' => 'upper',
    'collation' => 'emoji',
    'currency' => 'USD',
    'hourCycle' => 'h23',
    'language' => 'en',
    'numberingSystem' => 'latn',
    'numeric' => true,
    'region' => 'US',
    'script' => 'Latn',
];

foreach ($properties as $property => $value) {
    $options = new Options(...[$property => $value]);
    echo json_encode($options);
    echo "\n";
    
    foreach ($properties as $property2 => $value2) {
        if ($property === $property2) {
            continue;
        }
        
        $options = new Options(...[$property => $value, $property2 => $value2]);
        echo json_encode($options);
        echo "\n";
    }
}

--EXPECT--
{"calendar":"gregory"}
{"calendar":"gregory","caseFirst":"upper"}
{"calendar":"gregory","collation":"emoji"}
{"calendar":"gregory","currency":"USD"}
{"calendar":"gregory","hourCycle":"h23"}
{"calendar":"gregory","language":"en"}
{"calendar":"gregory","numberingSystem":"latn"}
{"calendar":"gregory","numeric":true}
{"calendar":"gregory","region":"US"}
{"calendar":"gregory","script":"Latn"}
{"caseFirst":"upper"}
{"calendar":"gregory","caseFirst":"upper"}
{"caseFirst":"upper","collation":"emoji"}
{"caseFirst":"upper","currency":"USD"}
{"caseFirst":"upper","hourCycle":"h23"}
{"caseFirst":"upper","language":"en"}
{"caseFirst":"upper","numberingSystem":"latn"}
{"caseFirst":"upper","numeric":true}
{"caseFirst":"upper","region":"US"}
{"caseFirst":"upper","script":"Latn"}
{"collation":"emoji"}
{"calendar":"gregory","collation":"emoji"}
{"caseFirst":"upper","collation":"emoji"}
{"collation":"emoji","currency":"USD"}
{"collation":"emoji","hourCycle":"h23"}
{"collation":"emoji","language":"en"}
{"collation":"emoji","numberingSystem":"latn"}
{"collation":"emoji","numeric":true}
{"collation":"emoji","region":"US"}
{"collation":"emoji","script":"Latn"}
{"currency":"USD"}
{"calendar":"gregory","currency":"USD"}
{"caseFirst":"upper","currency":"USD"}
{"collation":"emoji","currency":"USD"}
{"currency":"USD","hourCycle":"h23"}
{"currency":"USD","language":"en"}
{"currency":"USD","numberingSystem":"latn"}
{"currency":"USD","numeric":true}
{"currency":"USD","region":"US"}
{"currency":"USD","script":"Latn"}
{"hourCycle":"h23"}
{"calendar":"gregory","hourCycle":"h23"}
{"caseFirst":"upper","hourCycle":"h23"}
{"collation":"emoji","hourCycle":"h23"}
{"currency":"USD","hourCycle":"h23"}
{"hourCycle":"h23","language":"en"}
{"hourCycle":"h23","numberingSystem":"latn"}
{"hourCycle":"h23","numeric":true}
{"hourCycle":"h23","region":"US"}
{"hourCycle":"h23","script":"Latn"}
{"language":"en"}
{"calendar":"gregory","language":"en"}
{"caseFirst":"upper","language":"en"}
{"collation":"emoji","language":"en"}
{"currency":"USD","language":"en"}
{"hourCycle":"h23","language":"en"}
{"language":"en","numberingSystem":"latn"}
{"language":"en","numeric":true}
{"language":"en","region":"US"}
{"language":"en","script":"Latn"}
{"numberingSystem":"latn"}
{"calendar":"gregory","numberingSystem":"latn"}
{"caseFirst":"upper","numberingSystem":"latn"}
{"collation":"emoji","numberingSystem":"latn"}
{"currency":"USD","numberingSystem":"latn"}
{"hourCycle":"h23","numberingSystem":"latn"}
{"language":"en","numberingSystem":"latn"}
{"numberingSystem":"latn","numeric":true}
{"numberingSystem":"latn","region":"US"}
{"numberingSystem":"latn","script":"Latn"}
{"numeric":true}
{"calendar":"gregory","numeric":true}
{"caseFirst":"upper","numeric":true}
{"collation":"emoji","numeric":true}
{"currency":"USD","numeric":true}
{"hourCycle":"h23","numeric":true}
{"language":"en","numeric":true}
{"numberingSystem":"latn","numeric":true}
{"numeric":true,"region":"US"}
{"numeric":true,"script":"Latn"}
{"region":"US"}
{"calendar":"gregory","region":"US"}
{"caseFirst":"upper","region":"US"}
{"collation":"emoji","region":"US"}
{"currency":"USD","region":"US"}
{"hourCycle":"h23","region":"US"}
{"language":"en","region":"US"}
{"numberingSystem":"latn","region":"US"}
{"numeric":true,"region":"US"}
{"region":"US","script":"Latn"}
{"script":"Latn"}
{"calendar":"gregory","script":"Latn"}
{"caseFirst":"upper","script":"Latn"}
{"collation":"emoji","script":"Latn"}
{"currency":"USD","script":"Latn"}
{"hourCycle":"h23","script":"Latn"}
{"language":"en","script":"Latn"}
{"numberingSystem":"latn","script":"Latn"}
{"numeric":true,"script":"Latn"}
{"region":"US","script":"Latn"}
