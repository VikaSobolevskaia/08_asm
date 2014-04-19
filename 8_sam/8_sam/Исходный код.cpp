#include <iostream>
using namespace std;
void main()
{
	int a, b, sum;
	cout<<"a = ";
	cin>>a;
	cout<<"b = ";
	cin>>b;
	_asm
	{
		mov eax, a	// eax <- a
		add eax, b	// eax <- eax+b
		mov sum, eax
	}
	cout<<"sum = "<<sum<<endl;

	system("PAUSE");
}