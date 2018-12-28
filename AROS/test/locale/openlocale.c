/*
    Copyright � 1995-2016, The AROS Development Team. All rights reserved.
    $Id: openlocale.c 51327 2016-01-18 02:32:28Z neil $
*/

#include <proto/locale.h>
#include <proto/exec.h>
#include <stdio.h>
#include <string.h>

#include "../clib/test.h"

struct LocaleBase * LocaleBase = NULL;
struct Locale * locale = NULL;

void cleanup()
{
    if (locale) CloseLocale(locale);

    if (LocaleBase) CloseLibrary((struct Library *)LocaleBase);

}
int main(void)
{
    LocaleBase = (struct LocaleBase *)OpenLibrary("locale.library",0);

    if (LocaleBase)
    {
        int result = 0;

        locale = OpenLocale("openlocale.prefs");
        TEST(locale != NULL);

        /* Expected: name of the prefs file */
        result = strcmp(locale->loc_LocaleName, "openlocale.prefs");
        TEST(result == 0);

        /* Expected: native language name */
        result = strcmp(locale->loc_LanguageName, "polski.language");
        TEST(result == 0);

        /* Expected: native language name */
        result = strcmp(locale->loc_PrefLanguages[0], "polski");
        TEST(result == 0);

    }

    cleanup();

    return 0;
}
