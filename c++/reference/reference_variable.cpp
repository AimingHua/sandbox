#include <iostream>
using namespace std;

//1. reference must be initialized when declared, otherwise compiler will report 'declared as reference but not initialized' error
//2. can't assign anthor variable to reference after initialized
//3. declare a reference will not define a variable, just give target variable another name
int main()
{
	int x = 456;
    int a = 123;
    int &b = a; //variable b is alias of variable a, so same address between a and b, "&" state b is a reference
    int *c = &a; //variable c is a pointer which point to variable a

    cout << "variable a address: " << &a << endl;
    cout << "variable b address: " << &b << endl;
    cout << "variable c pointto: " << c << endl;
    cout << "variable c address: " << &c << endl;

	//compile is okay, and will cause b,a and x represent same variable
	//b = x; 

    cout << "a= " << a << endl;
    cout << "b= " << b << endl;
	cout << "&c= " << &c << endl;
	cout << " c= " << c << endl;
    cout << "*c= " << *c << endl;
}
