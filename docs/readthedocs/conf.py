# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

import os
import sphinx_rtd_theme
import sys
import datetime

from pygments.lexers.web import PhpLexer
from sphinx.highlighting import lexers
from subprocess import Popen, PIPE


def get_version():
    if os.environ.get('READTHEDOCS') == 'True':
        return os.environ.get('READTHEDOCS_VERSION')

    pipe = Popen('git branch | grep \*', stdout=PIPE, shell=True, universal_newlines=True)
    version = pipe.stdout.read()

    if version:
        return version[2:]
    else:
        return 'unknown'


# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'pecl/ecma_intl'
copyright = '{year}, php-ecma-intl contributors'.format(year=datetime.date.today().strftime('%Y'))
author = 'php-ecma-intl contributors'

version = get_version().strip()
release = version

today = datetime.date.today().strftime('%Y-%m-%d')

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

master_doc = 'index'
highlight_language = 'php'

# enable highlighting for PHP code not between ``<?php ... ?>`` by default
lexers['php'] = PhpLexer(startinline=True)
lexers['php-annotations'] = PhpLexer(startinline=True)

extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.todo',
    'sphinxcontrib.phpdomain',
]

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

pygments_style = 'sphinx'

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_theme_options = {
    'collapse_navigation': False,
    'display_version': False
}

html_static_path = ['_static']
html_title = "ecma_intl %s" % get_version()
html_show_sphinx = False

html_context = {
    "display_github": True,
    "github_user": "php-ecma-intl",
    "github_repo": "ext",
    "github_version": version,
    "conf_py_path": "/docs/readthedocs/",
}

current_year = datetime.date.today().strftime('%Y')
rst_prolog = """
.. |current_year| replace:: {0}
""".format(current_year)
