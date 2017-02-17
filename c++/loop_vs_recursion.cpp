#include <iostream>
using namespace std;

int sum1(int n)
{
    cout << "enter sum1() with &n=, n=" << &n << n << endl;
    int total = 0;
    for(int i=1; i<=n; i++)
       total += i;

    return total;
}

int sum2(int n)
{
    cout << "enter sum2() with &n=, n=" << &n << n << endl;
    //don't need variable total
    if(n==1) return 1;
    return (sum2(n-1)+n);
}

int main()
{
    cout << "loop sum(5)=" << sum1(5) << endl;
    cout << "loop sum(5)=" << sum1(5) << endl;
    cout << "recursion sum2(5)=" << sum2(5) << endl;
    cout << "recursion sum2(5)=" << sum2(5) << endl;
    return 0;
}
