In mathematics, a pandigital number is an integer that in a given base has among its significant digits each digit used in the base 
at least once. For example, 1223334444555556666667777777888888889999999990 is a pandigital number in base 10. 
The first few pandigital base 10 numbers are given by (sequence A050278 in the OEIS):
1023456789, 1023456798, 1023456879, 1023456897, 1023456978, 1023456987, 1023457689

Code:
#include<stdio.h>
#include<limits.h>
int main()
{
	short int check = 0;
	long long int num;
	scanf("%lld",&num);
	while(num!=0)
	{
		check = check | ( 1 << (num%10));
		num = num / 10;
	}
	if(check == 1023)
		printf("PANDIGITAL");
	else
		printf("NOT PANDIGITAL");
	return 0;
}
