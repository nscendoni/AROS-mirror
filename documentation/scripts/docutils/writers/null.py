# Author: David Goodger
# Contact: goodger@python.org
# Revision: $Revision: 30800 $
# Date: $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
# Copyright: This module has been placed in the public domain.

"""
A do-nothing Writer.
"""

from docutils import writers


class Writer(writers.UnfilteredWriter):

    supported = ('null',)
    """Formats this writer supports."""

    config_section = 'null writer'
    config_section_dependencies = ('writers',)

    def translate(self):
        pass
