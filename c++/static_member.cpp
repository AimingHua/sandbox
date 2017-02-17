#include <iostream>
using namespace std;

/*
 * key points:
 * 1. declare and define class static menber
 * 2. static member share by all objects
 * 3. static member can access by object and class
 * 4. static member share by derived class
 * 5. static function member can ONLY access static data member
 * */

class Base
{
	public:
		static int a; //declare static member
		static void display();

	private:
		static int b;
        int c; 
};

void Base::display()
{
	//static function member can't access no static data member
	//cout << "c= " << c << endl;
	
	cout << "Display(): a= " << a << endl;
}

class Derived: public Base
{
};

//if not define here, compile error: undefined reference to `B::a'
int Base::a = 1; //Note!!! define static member
int Base::b = 1; //Note!!! it's okay

int main()
{
	//access by class
	Base::a++;
	//Base::b++; //compile report: 'int Base::b' is private
	cout << "Base::a= " << Base::a << endl;

	//access by object
	Base b;
	//b.b++ //'int Base::b' is private
	cout << "b.a= " << b.a << endl;

	//access by derived class
	Derived::a++;
	//Derived::b++; //'int Base::b' is private
	cout << "Derived::a= " << Derived::a << endl;

	//access by object of derived class
	Derived d;
	//d.b++; //int Base::b' is private
	cout << "d.a= " << d.a << endl;

	//can call static function member both by class and object
	Base::display();
	b.display();

}
