#include <iostream>
using namespace std;
void main()
{
	int n, result;
	cout<<"n = ";
	cin>>n;
	_asm
	{
		sub ebx, ebx // sum=0- ebx
		mov ecx, 1   // ecx-deliteli
cycle_start:
		cmp ecx, n   //sravnenie
		je cycle_end //jump equal
		mov eax, n
		cdq          // edx:eax- delimoe
		div ecx      //eax-chastnoe, edx- ostatok
		cmp edx, 0 
		jne not_delitel
		add ebx, ecx // sum 
not_delitel:
		inc ecx // ++ecx
		jmp cycle_start
cycle_end:
		mov eax, 0
		cmp ebx, n
		jne asm_end
		inc eax 
asm_end:
		mov result, eax

	}
	if (result==0)
		cout<<"ne sover\n";
	else
		cout<<"sover\n";

}