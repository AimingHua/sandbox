#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

class base
{
    private:
	int a;
};

class derived : public base
{
    private:
	int b;
};

int main()
{
    int a;
    int *p;
    base b;
    derived d;
    cout << "a is: " << typeid(a).name() << endl;
    cout << "*p is: " << typeid(p).name() << endl;
    cout << "b is: " << typeid(b).name() << endl;
    cout << "d is: " << typeid(d).name() << endl; 
    
}
