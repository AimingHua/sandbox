#include <iostream>
#include <stdio.h>
using namespace std;
/*
*/

void print_short()
{
        union
	{
		short i;
		char c[2];
	} a;
	a.i = 0x01;
        printf("short i=0x%x\r\n", a.i);
	for(int k=1; k>=0; k--)
		printf("%p: 0x%x \r\n", &a.c[k], a.c[k]);
}

void print_int()
{
	union
	{
		int i;
		unsigned char c[4];
	} s;
	s.i = 0x01020304;
        printf("int i=0x%x \r\n", s.i);
	for(int k=3; k>=0; k--)
	    printf("%p: %d\r\n", &s.c[k], s.c[k]);
}

void print_long()
{
	union
	{
		long l;
		char c[8];
	} u;
	u.l = 0x102030405060708;
        printf("long i=%ld \r\n", u.l);
	for(int k=7; k>=0; k--)
		printf("%p: 0x%x \r\n", &u.c[k], u.c[k]);
}

int main()
{
        int n=1;
        if(*(char *)&n == 1)
            printf("system is little endian\r\n");
	print_short();
	print_int();
	print_long();
}
