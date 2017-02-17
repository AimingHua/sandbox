#include <stdio.h>

int add(int x, int y)
{
	return x+y;
}

int main()
{
	int p = add(3,4);
	printf("%d\r\n", p);
	return 0;
}
