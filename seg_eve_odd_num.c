INPUT : 12345
OUTPUT : 24135
#include<stdio.h>
int main()
{
	int Num,Odd_Num=0,Even_Num=0,Odd_pow=1,Even_pow=1,digit;
	scanf("%d",&Num);
	while( Num!= 0)
	{
		digit = Num % 10 ;
		if( digit % 2 == 0 )
		{
			Even_Num += digit * Even_pow ;
			Even_pow *= 10 ;  	
		} 
		else
		{
			Odd_Num += digit * Odd_pow ;
			Odd_pow *= 10 ;
		}
		Num /= 10 ;
	}
	Num = Even_Num * Odd_pow + Odd_Num ;
	printf("%d", Num );
	return 0;
}
