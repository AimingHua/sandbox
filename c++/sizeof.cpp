/* sizeof is used to calculate size of memory allocated in stack, unit: byte
 * 1. */ 
#include <iostream>
using namespace std;

class h {
};

char fun(void)
{
    char a = 'a';
    return a;
}

static char a = 10;
int main()
{
   int    b;
   short  c;
   long   d;
   float  e;
   double f;
   short *p = (short *)malloc(sizeof(short));

   cout << "sizeof(char)="   << sizeof(char)   << endl;
   //cout << "sizeof char="    << sizeof char    << endl; //sizeof type name, must use sizeof(type name)
   cout << "sizeof a="       << sizeof a       << endl;   //sizeof variable, sizeof(xx)/sizeof xx both okay 
   cout << "sizeof(short)="  << sizeof(short)  << endl;
   cout << "sizeof(int)="    << sizeof(int)    << endl;
   cout << "sizeof(long)="   << sizeof(long)   << endl;
   cout << "sizeof(float)="  << sizeof(float)  << endl;
   cout << "sizeof(double)=" << sizeof(double) << endl;
   cout << "sizeof(fun())="  << sizeof(fun())  << endl;
   cout << "sizeof(h)="      << sizeof(h)      << endl; //size of empty class: 1
   cout << "sizeof(a)="      << sizeof(a)      << endl; //calculate static variable
   cout << "sizeof(*p)="     << sizeof(*p)     << endl; //calculate size of memory allocated in heap
   cout << "sizeof(p)="      << sizeof(p)      << endl; //calculate size of pointer: 32-bit system: 4 bytes; 64-bit system: 8bytes
   return 0;
}
