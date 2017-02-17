#include <stdio.h>

extern int global_init_a;
int main(void)
{
    printf("global_init_a=%d\r\b", global_init_a);
}
