#include <iostream>
using namespace std;

int main()
{
	int ar[2] = {1,2};
	int (*p1)[2];
	char *p2[] = {"c++", "erlang", "MFC"};

	p1 = ar;
	//cout << "p1[0]" << p1[0] << endl;
	//cout << "p1[1]" << p1[1] << endl;
	cout << p2[0] << endl;
	cout << p2[1] << endl;
	cout << p2[2] << endl;
}
