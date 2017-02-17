#include <stdio.h>
//double global_init_var = 1; //strong symbol
double global_uninit_var; //weak symbol
//double global_uninit_var __attribute__((nocommon)); //strong symbol
int main(void)
{
    return 0;
}
