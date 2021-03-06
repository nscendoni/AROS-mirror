/*
    Copyright � 1995-2013, The AROS Development Team. All rights reserved.
    $Id: australia.c 50781 2015-06-06 21:56:09Z polluks $

    Desc: Country data for Australia.
    Author: Iain Templeton <iain@ugh.net.au>
*/

#include "country_locale.h"
#include <libraries/locale.h>

struct IntCountryPrefs australiaPrefs =
{
    {
        /* Reserved */
        { 0, 0, 0, 0 },

        /* Country code (licence plate number), telephone code, measuring system */
        MAKE_ID('A','U','S',0), 61, MS_ISO,

        /* Date time format, date format, time format */
        "%A %B %e %Y %I:%M%p",
        "%A %B %e %Y",
        "%I:%M:%S%p",

        /* Short datetime, short date, short time formats */
        "%e/%m/%y %I:%M%p",
        "%e/%m/%y",
        "%I:%M%p",

        /* Decimal point, group separator, frac group separator */
        ".", " ", "",

        /* For grouping rules, see <libraries/locale.h> */

        /* Grouping, Frac Grouping */
        { 3 }, { 0 },

        /* Mon dec pt, mon group sep, mon frac group sep */
        ".", " ", "",

        /* Mon Grouping, Mon frac grouping */
        { 3 }, { 0 },

        /* Mon Frac digits, Mon IntFrac digits, then number of digits in
           the fractional part of the money value. Most countries that
           use dollars and cents, would have 2 for this value

           (As would many of those you don't).
        */
        2, 2,

        /* Currency symbol, Small currency symbol */
        "$", "c",

        /* Int CS, this is the ISO 4217 symbol, followed by the character to
           separate that symbol from the rest of the money. (\x00 for none).
        */
        "AUD",

        /* Mon +ve sign, +ve space sep, +ve sign pos, +ve cs pos */
        "", SS_SPACE, SP_PREC_ALL, CSP_PRECEDES,

        /* Mon -ve sign, -ve space sep, -ve sign pos, -ve cs pos */
        "-", SS_NOSPACE, SP_PARENS, CSP_PRECEDES,

        /* Calendar type */
        CT_7MON
    },
    "$VER: australia.country 44.1 (06.06.2015)",
    NULL,
    "Countries/Australia"
};
