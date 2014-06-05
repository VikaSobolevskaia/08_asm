#include <iostream>
#include <time.h>
using namespace std;

extern "C" int __fastcall equal_int(int, int);
extern "C" int __cdecl greater_int(int, int);
extern "C" int __stdcall less_int(int, int);

void main()
{
	int a,b;
	srand(time(0));
	a = rand()%100+1;	// 1-100
	cout << "a = " << a << endl;

	b = -a;
	while (!equal_int(a,b))
	{
		cout << "Enter number: ";
		cin >> b;
		if (greater_int(b,a))
			cout << "Greater\n";
		if (less_int(b,a))
			cout << "Less\n";
	}

	cout << "Game was finished\n";

}