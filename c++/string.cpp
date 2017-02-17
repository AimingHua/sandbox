#include <iostream>
using namespace std;

//invalid initialization of non-const reference of type 'std::string&' from a temporary of type 'const char*'
/*
string& foo()
{
	return "hello world";
}
*/

//warning: returning reference to temporary
/*
const string& foo1()
{
	return "hello world";
}
*/

char *foo2()
{
	//compiler will put string literal in static storage space/static memory/read-only section
	return "hello world";
}

string foo3()
{
	return "hello world";
}

void display(char *str)
{
	while(*str)
		cout << *str++;
	cout << endl;
}

int main()
{
	//display(foo2());
	cout << foo3() << endl;
}
