#include <stdio.h>

/*
static seems to be a poorly chosen keyword for specifying linkage, and has confused many, if not all C programmers at some point (it's choice for describing storage duration, however, is excellent). There is nothing particularly static about something with internal (static) linkage. They don't stay in one place any more than their non-static counterparts. A more appropriate choice might have been intern(al) or private, but it's too late now
*/

/*
 *static = intern
 */

/*
 *extern is default keyword 
 */

/*this module internal functions*/
static void bar(void)
{
    puts("I'm bar(), and I can only be called from within foo.c");
}

/*this module external functions*/
extern void foo(void)
{
    puts("I'm foo(), and I can be called from any file that includes foo.h");
    bar();
}
