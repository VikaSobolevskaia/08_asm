#include <iostream>
#include <limits.h>
using namespace std;

void main()
{
	int A[5] = {-3, 2, 5, -3, 4};
	int n = 5;
	int max1, max2, max3, min1, min2;
	max1 = max2 = max3 = INT_MIN;
	min1 = min2 = INT_MAX;

	__asm
	{
		sub	 esi, esi		// A[i] ~ A[4*esi]
	begin_cycle:
		cmp  esi, n
		je	 end_cycle
		mov	 eax, A[4*esi]	// eax <- A[i]
		cmp  eax, max1
		jle	 m_max2
		push max2
		pop	 max3
		push max1
		pop  max2
		mov  max1, eax	// max1 = A[i]
		jmp  m_min1
	m_max2:
		cmp  eax, max2
		jle  m_max3
		push max2
		pop  max3
		mov	 max2, eax
		jmp  m_min1
	m_max3:
		cmp  eax, max3
		jle  m_min1
		mov	 max3, eax	// max3 = A[i]
	m_min1:
		cmp  eax, min1
		jge  m_min2
		push min1
		pop  min2
		mov  min1, eax
		jmp  m_next
	m_min2:
		cmp  eax, min2
		jge  m_next
		mov	 min2, eax	// min2 = A[i]
	m_next:
		inc  esi
		jmp  begin_cycle

	end_cycle:
	}
	
	cout << "max1=" << max1 << endl;
	cout << "max2=" << max2 << endl;
	cout << "max3=" << max3 << endl;
	cout << "min1=" << min1 << endl;
	cout << "min2=" << min2 << endl;

	if ( (max1>0) && (min1*min2>max2*max3) )
		cout << "Result: " << max1 << "; " << min1 << "; " << min2 << endl;
	else
		cout << "Result: " << max1 << "; " << max2 << "; " << max3 << endl;

}