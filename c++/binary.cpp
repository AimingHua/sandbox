#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	char a = -5;
	std::bitset<8> x(a);
	std::cout << x << endl;
}
