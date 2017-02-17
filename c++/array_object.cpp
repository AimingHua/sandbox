#include <iostream>
using namespace std;

class B
{
	public:
		B(){};
};

int main()
{
    B b[10];
	B *p = new B[10];
}
