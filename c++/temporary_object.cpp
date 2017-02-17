#include <iostream>
using namespace std;

class X
{
	int i;
	public:
	X(int ii=0);
	~X();
	void modify();
};

X::X(int ii)
{
	i = ii;
	cout << "constructor" << endl;
}

X::~X()
{
	cout << "destructor" << endl;
}

void X::modify()
{
	i++;
}

X f5()
{
	return X();
}

const X f6()
{
	return X();
}

void f7(X& x)
{
	x.modify();
}

void f8(const string &str)
{
}

int main()
{
	//f5() = X(1);   //OK
	//f5().modify(); //OK

    //compile error: invalid initialization of non-const reference of type 'X&' from a temporary of type 'X'
	//f7(f5());

	//compile error: passing 'const X' as 'this' argument of 'X& X::operator=(const X&)' discards qualifiers
	//f6() = X(2);

	//compile error: passing 'const X' as 'this' argument of 'void X::modify()' discards qualifiers
	//f6().modify();

	//compile error: invalid initialization of non-const reference of type 'X&' from a temporary of type 'const X
	//f7(f6());

	//invalid initialization of non-const reference of type 'std::string&' from a temporary of type 'const char*'
	f8("abc");
	return 0;
}
