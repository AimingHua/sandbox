#include <iostream>
#include <stdio.h>
using namespace std;

/*
    32-bit system:
    int x = 1;

	Big Endian: same as reading habit 
    low memory address --> higher memory address
	+----+----+----+----+
	|0x00|0x00|0x00|0x01|
	+----+----+----+----+
	A
	|
	&x

	Little Endian: reverse as reading habit 
    low memory address --> higher memory address
	+----+----+----+----+
	|0x01|0x00|0x00|0x00|
	+----+----+----+----+
	A
	|
	&x

*/
void print_int()
{
	int n = 1;
	char *c = (char *)&n;
	if(*c == 1)
		cout << "system is little endian" << endl;
	else
		cout << "system is big endian" << endl;

	union
	{
		int i;
		unsigned char c[4];
	} s;
	s.i = 0x0a0b0c0d;

	printf("int i = 0x0a0b0c0d, sizeof(int)=%d\r\n", sizeof(int));
	printf("-----------+-----------+-----------+-----------+\r\n");
	for(int k=0; k<4; k++)
		printf("0x%x |", &s.c[k]);
	printf("\r\n");
	printf("-----------|-----------|-----------|-----------|\r\n");
	for(int k=0; k<4; k++)
		printf("       0x%x |", (int)s.c[k]);
	printf("\r\n");
	printf("-----------+-----------+-----------+-----------+\r\n");
}

void print_short()
{
	short n = 1;
	char *p = (char *)&n;
	if(*p == 0)
		printf("system is big endian\r\n");
	else 
		printf("system is little endian\r\n");
        union
	{
		short i;
		char c[2];
	} a;
	a.i = 0x0a0b;
	printf("short i = 0x0a0b, sizeof(short)=%d\r\n", sizeof(short));
	printf("-----------+-----------+\r\n");
	for(int k=0; k<2; k++)
		printf("0x%x |", &a.c[k]);
	printf("\r\n");
	printf("-----------|-----------|\r\n");
	for(int k=0; k<2; k++)
		printf("       0x%x |", (int)a.c[k]);
	printf("\r\n");
	printf("-----------+-----------+\r\n");
}

void print_long()
{
	//int l = 0x08090a0b0c0d0e0f; //warning: overflow in implicit constant conversion
	long l = 1;
	char *c = (char *)&l;
	if(*c == 0)
		printf("system is big endian\r\n");
	else
		printf("system is little endian\r\n");

	union
	{
		long l;
		char c[8];
	} u;
	u.l = 0x08090a0b0c0d0e0f;
	printf("long l = 0x08090a0b0c0d0e0f, sizeof(long)=%d\r\n", sizeof(long));
	printf("-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\r\n");
	for(int k=0; k<8; k++)
		printf("0x%x |", &u.c[k]);
	printf("\r\n");
	printf("-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|\r\n");
	for(int k=0; k<8; k++)
		printf("       0x%x |", (int)u.c[k]);
	printf("\r\n");
	printf("-----------+-----------+-----------+-----------+-----------+-----------+-----------+-----------+\r\n");
	
}

int main()
{
	print_short();
	print_int();
	print_long();
}
