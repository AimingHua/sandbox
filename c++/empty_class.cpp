#include <iostream>
using namespace std;

/*
  Why the size of empty class is not zero?
  1. To ensure that the address of different objects will be different, new always returns pointers to distinct objects
  2. But an empty base class need not be presented by a seperated byte
*/

class Empty
{
};

class A: public Empty
{
	private:
		int i;
};

int main()
{
	Empty e;
	A a;
	cout << "sizeof(Empty)=" << sizeof(Empty) << endl; //size is 1, but not 0
	cout << "sizeof(A)=" << sizeof(A) << endl; //size is 4, but not 5, compiler provide 'empty base class optimization'

}
