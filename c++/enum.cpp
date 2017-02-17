#include <iostream>
using namespace std;
enum Color {red, green, blue};
enum Card {red_card, green_card, yellow_card};
//enum class Animal {dog, deer, cat, bird, human};
//enum class Mammal {kangaroo, deer, human};

void fun() {
	Color color = green;
	Card card = yellow_card;
	int num = color;
	cout << "color=" << color << endl;
	cout << "card=" << card << endl;
	cout << "num=" << num << endl; 
}
int main()
{
	fun();
}
