#ifndef COUNTRY_LOCALE_H
#define COUNTRY_LOCALE_H
/*
    Copyright © 2013, The AROS Development Team. All rights reserved.
    $Id: country_locale.h 51226 2015-12-03 13:53:57Z polluks $
*/

#include <prefs/locale.h>

struct IntCountryPrefs {
    struct CountryPrefs country_CP;
    char        *country_Version;
    char        *country_NativeNames;
    char        *country_Flag;
};

#endif /* COUNTRY_LOCALE_H */
