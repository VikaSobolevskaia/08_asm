#include <iostream>
using namespace std;

void main()
{
	int A[3][4] = {
		{100,2,33,4},
		{5,600,77,8},
		{900,10,11,1200}
	};
	int B[4][3];
	int n=3, m=4;

	//for (i=0; i<n; ++i)
	//	for (j=0; j<m; ++j)
	//		B[j][i] = A[i][j];
	// Metod, str 25
	__asm
	{
		mov ecx,0			; i � ����� ������� ������ A
	begin_n:
		mov ebx,0			; j � ����� �������� �������� A
	begin_m:
		// ����� A[i][j] ����� A+(i*m+j)*������ ��������
		// ��������� i*m+j
		mov eax,m
		mul ecx
		add eax,ebx
		mov esi,eax			; esi <- (i*m+j)
		mov edi,A[esi*4]	; edi <- A[i][j]
		// ����� B[j][i] ����� B+(j*n+i)*������ ��������
		// ��������� j*n+i
		mov eax,n
		mul ebx
		add eax,ecx
		mov esi,eax			; esi <- (j*n+i)
		mov B[esi*4],edi	; B[j][i] <- edi
		inc ebx				; � ���������� �������� � ������
		cmp ebx,m
		jl begin_m			; �� ��� �������� ������ i ����������
		
		inc ecx				; � ��������� ������
		cmp ecx,n
		jl begin_n			; �� ��� ������ ����������
	}

	for(int i=0; i<m; ++i)
	{
		for (int j=0; j<n; ++j)
			cout << B[i][j] << '\t';
		cout << endl;
	}
}