#include <stdio.h>
#include <stdlib.h>

short var_bss1;
short var_bss2;
short var_data1=1;

int main()
{
    printf("*******************\r\n");
    printf("*  stack segment  *\r\n");
    printf("*  heap  segment  *\r\n");
    printf("*  bss   segment  *\r\n");
    printf("*  data  segment  *\r\n");
    printf("*  code  segment  *\r\n");
    printf("*******************\r\n");

    static short var_data2=1;
    short var_stack1;
    short var_stack2;
    void *var_code = (void *)main;
    short *var_heap1 = (short *)malloc(sizeof(short));
    short *var_heap2 = (short *)malloc(sizeof(short));
    printf("stack segment: \r\n");
    printf("&var_stack1: %p\r\n", &var_stack1);
    printf("&var_stack2: %p\r\n", &var_stack2);
    printf("heap segment: \r\n");
    printf("&var_heap1: %p\r\n", var_heap1);
    printf("&var_heap2: %p\r\n", var_heap2);
    printf("bss segment: \r\n");
    printf("&var_bss1: %p\r\n", &var_bss1);
    printf("&var_bss2: %p\r\n", &var_bss2);
    printf("data segment: \r\n");
    printf("&var_data1: %p\r\n", &var_data1);
    printf("&var_data2: %p\r\n", &var_data2);
    printf("code segment: %p\r\n", var_code);

    free(var_heap1);
    free(var_heap2);
}
