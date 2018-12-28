/*
    Copyright © 1995-2014, The AROS Development Team. All rights reserved.
    $Id: test.h 48976 2014-04-29 15:24:29Z neil $
*/

/* Prototypes for mandatory functions */
void cleanup( void );

/* Return values */
#define OK   0	/* All tests succeeded */
#define FAIL 5  /* Some of the tests failed */

/* Testing macro */
#define TEST(x) \
        if(!(x))                                                            \
        {                                                                   \
            printf( "Test FAILED in %s, line %d.\n", __FILE__, __LINE__ );  \
            cleanup();                                                      \
            return FAIL;                                                    \
        }                                                                   \
        else                                                                \
        {                                                                   \
            printf( "Test passed in %s, line %d.\n", __FILE__, __LINE__ );  \
        }        

/* Only output when not passing */
#define TESTFALSE(x) \
        if(!(x))                                                            \
        {                                                                   \
            printf( "Test FAILED in %s, line %d.\n", __FILE__, __LINE__ );  \
            cleanup();                                                      \
            return FAIL;                                                    \
        }

