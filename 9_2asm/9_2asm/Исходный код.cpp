#include <iostream>
using namespace std;
void main()
{
	int n, result;
	cout<<"n = ";
	cin>>n;
	_asm
	{
		sub ebx, ebx // ebx=0 ; kolichestvo delitilei
		mov ecx, 1   // ecx-deliteli
cycle_start:
		cmp ecx, n   //sravnenie
		jg cycle_end //jump greater
		mov eax, n
		cdq          // edx:eax- delimoe
		div ecx      //eax-chastnoe, edx- ostatok
		cmp edx, 0 
		jne not_delitel
		inc ebx // ++ebx 
not_delitel:
		inc ecx // ++ecx
		jmp cycle_start
cycle_end:
		mov result, ebx

	}
	cout<<n<<" imeet "<<result<<" deliteli\n";


}