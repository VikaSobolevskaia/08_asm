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
		mov ecx,0			; i Ц номер текущей строки A
	begin_n:
		mov ebx,0			; j Ц номер текущего элемента A
	begin_m:
		// адрес A[i][j] равен A+(i*m+j)*размер элемента
		// вычисл€ем i*m+j
		mov eax,m
		mul ecx
		add eax,ebx
		mov esi,eax			; esi <- (i*m+j)
		mov edi,A[esi*4]	; edi <- A[i][j]
		// адрес B[j][i] равен B+(j*n+i)*размер элемента
		// вычисл€ем j*n+i
		mov eax,n
		mul ebx
		add eax,ecx
		mov esi,eax			; esi <- (j*n+i)
		mov B[esi*4],edi	; B[j][i] <- edi
		inc ebx				; к следующему элементу в строке
		cmp ebx,m
		jl begin_m			; не все элементы строки i обработаны
		
		inc ecx				; к следующей строке
		cmp ecx,n
		jl begin_n			; не все строки обработаны
	}

	for(int i=0; i<m; ++i)
	{
		for (int j=0; j<n; ++j)
			cout << B[i][j] << '\t';
		cout << endl;
	}
}