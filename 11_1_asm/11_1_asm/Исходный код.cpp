#include <iostream>
using namespace std;

void main()
{
	char str[100], c;
	cout << "Enter str: ";
	cin >> str;
	cout << "Enter c: ";
	cin >> c;
	int index = -1;

	__asm
	{
		sub esi, esi		// str[esi]
		mov	al, c			
	
	begin_cycle:
		cmp str[esi], 0		// konec str
		je	str_end
		cmp	str[esi], al	// str[i]?c
		jne next_str_i
		mov index, esi
	next_str_i:
		inc esi
		jmp begin_cycle

	str_end:
	}

	cout << "index = " << index << endl;
}