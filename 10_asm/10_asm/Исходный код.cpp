#include <iostream>
using namespace std;
void main()
{
	int n, i;
	double px, x, fa, s0, p1, s2, p3, fp1;
	cout<<"n = ";
	cin>>n;
	cout<<"x = ";
	cin>>x;
	px=x;
	fa=1;
	s0=0;
	p1=1;
	s2=0;
	p3=1;
	/*for (i=1; i<=n; ++i)
	{
		s0=s0+px;
		p1=p1*s0;
		fp1=p1/fa;
		s2=s2+fp1;
		p3=p3*s2; 
		px=px*x;
		fa=fa*(i+1);
	}*/
	_asm
	{
		mov i, 1
		finit //инициализация сопроцессора
cycle_start:
		fld s0
		fld px
		fadd //s0+px
		fstp s0

		fld p1
		fld s0
		fmul //p1
		fstp p1

		fld p1
		fld fa
		fdiv //fp1
		fstp fp1

		fld s2
		fld fp1
		fadd
		fstp s2

		fld p3
		fld s2
		fmul 
		fstp p3

		fld px
		fld x
		fmul
		fstp px

		inc i
		fld fa
		fild i
		fmul
		fstp fa
		
		mov eax, i
		cmp eax, n
		jle cycle_start //i<=n
	}
	cout<<"s0 = "<<s0<<endl;
	cout<<"p1 = "<<p1<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"p3 = "<<p3<<endl;
}