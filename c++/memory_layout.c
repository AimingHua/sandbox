#include <stdio.h>
#include <stdlib.h>

short var_bss;
short var_data=1;

int main()
{
    printf("*******************\r\n");
    printf("*  stack segment  *\r\n");
    printf("*  heap  segment  *\r\n");
    printf("*  bss   segment  *\r\n");
    printf("*  data  segment  *\r\n");
    printf("*  code  segment  *\r\n");
    printf("*******************\r\n");

    short var_stack;
    void *var_code = (void *)main;
    short *var_heap = (short *)malloc(sizeof(short));
    printf("stack segment: %p\r\n", &var_stack);
    printf("heap  segment: %p\r\n", var_heap);
    printf("bss   segment: %p\r\n", &var_bss);
    printf("data  segment: %p\r\n", &var_data);
    printf("code  segment: %p\r\n", var_code);

    free(var_heap);
}
