/* c memory layout
 * readelf -S xx: to read object file section information
 * objdump also can dump object file section info
 * dynamic zone:
 * 1. stack: function parameters, local variable 
 * 2. heap: malloc/free, new/delete, allocate and free by programer 
 * static zone:
 * 3. code/text: code
 * Data:
 * 4. RO Data: read only data
 * 5. RW Data: read write data
 * 6. BSS: uninitialzed RW data, block start by symbol */

#include <iostream>
#include <stdlib.h>
#include <string.h>

const  char ro[]={"this is read only data"};  //ro[] on 4.RO data, being const
static char rw_1[]={"this is global read write data"}; //5. rw_1[] on RW data 
char BSS_1[100]; //6.BSS
const char *ptr="constant data"; //"constant data" on RO data, ptr on RW data

int main()
{
    short b;            //1.stack, 2 bytes
    char a[100];        //1.stack, 100 bytes
    char s[]="abcdefg"; //s[] on stack
    char *p1;           //p1 on 1.stack, 4 bytes
    char *p2="123456";  //p2 on 1.stack, 4 bytes; "123456" on 4.RO data

    static char rw_2[]="local read write data"; //local, 5.RW data
    static char BSS_2[100]; //local, 6.BSS, uninitialized RW data
    static int c = 0;       //local, 5.RW data
    p1 = (char *)malloc(10*sizeof(char)); //allocate memory on 2.heap
    strcpy(p1, "xxxx"); //"xxxx" on RO data, 5 bytes
    free(p1);
    return 0;
}
