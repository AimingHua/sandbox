#include <iostream>
using namespace std;

string str("hello");

int main()
{
	for(int i=0; i<str.size(); i++)
		printf("%c\r\n",str[i]);
	for(char c:str)
		printf("%c\r\n",c);
}
