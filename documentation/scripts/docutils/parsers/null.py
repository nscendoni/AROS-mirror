# Author: Martin Blais
# Contact: blais@furius.ca
# Revision: $Revision: 30800 $
# Date: $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
# Copyright: This module has been placed in the public domain.

"""A do-nothing parser."""

from docutils import parsers


class Parser(parsers.Parser):

    """A do-nothing parser."""

    supported = ('null',)

    config_section = 'null parser'
    config_section_dependencies = ('parsers',)

    def parse(self, inputstring, document):
        pass
