# Author: David Goodger
# Contact: goodger@users.sourceforge.net
# Revision: $Revision: 30800 $
# Date: $Date: 2009-03-08 18:28:50 +0100 (Sun, 08 Mar 2009) $
# Copyright: This module has been placed in the public domain.

# Internationalization details are documented in
# <http://docutils.sf.net/docs/howto/i18n.html>.

"""
This package contains modules for language-dependent features of Docutils.
"""

__docformat__ = 'reStructuredText'

_languages = {}

def get_language(language_code):
    if _languages.has_key(language_code):
        return _languages[language_code]
    module = __import__(language_code, globals(), locals())
    _languages[language_code] = module
    return module
