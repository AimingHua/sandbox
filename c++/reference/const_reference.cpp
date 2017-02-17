#include <iostream>
#include <string>
using namespace std;

/*
key points: 
1. const reference is read-only, so can't change value by const reference
2. 'return of function' and 'constant' are temporary object, and temporary object are const
3. can't use const object to initialize reference 
*/

void bar(string &str)
{
    cout << str << endl;
}

void bar2(const string &str)
{
    cout << str << endl;
}

string foo(void)
{
	return "string return from a function is temporary object";
}

int main()
{
    int a;
    const int &b = a;
    a = 123;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
	a = 456;
	cout << endl;
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;

	//compiler will report: assignment of read-only reference 'b'
    //b = 234;

	//compile error: invalid initialization of non-const reference of type 'std::string&' from a temporary of type 'const char*'
	//bar("hello world");
	//bar2 paramter is const reference, it's okay
	bar2("i am a temporary variable, and temporary variable is const");
	//bar(foo());
	bar2(foo());
}
