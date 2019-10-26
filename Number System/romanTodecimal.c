#include<stdio.h>
#define MAX 20
int value(char a)
{
	if( a == 'I')
		return 1;
	if( a == 'V')
		return 5;
	if( a == 'X')
		return 10;
	if( a == 'L')
		return 50;
	if( a == 'C')
		return 100;
	if( a == 'D')
		return 500;
	if( a == 'M')
		return 1000;
}
int toDecimal(char *roman)
{
	int ind, sum = 0;
	for( ind = 0 ; roman[ind] ; )
	{
		if( value(roman[ind]) >= value(roman[ind+1]))
		{
			sum = sum + value(roman[ind]);
			ind++;
		}
		else
		{	
			sum = sum + value(roman[ind+1]) - value(roman[ind]);
			ind = ind + 2;
		}
	}
	return sum;
}
int main()
{
	char roman[MAX];
	int decimal;
	scanf("%s", roman);
	decimal = toDecimal(roman);
	printf("%s ====> %d", roman, decimal);
	return 0;
}
