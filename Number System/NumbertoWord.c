// Convert the given number to word
Range : 0 to 9999
Code:
#include<stdio.h>
#define MAX 15
int power(int num)
{
	int power10 = 1;
	while( num / power10 )
		power10 = power10 * 10;
	return power10 / 10;
}
int main()
{
	char ones[][MAX] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	char teen[][MAX] = { "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	char tens[][MAX] = { "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	int number, power10, digit;
	scanf("%d", &number);
	power10 = power(number);
	while( number / power10 != number )
	{
		digit = ( number / power10 ) % 10;
		if( power10 == 1000 && digit != 0 )
			printf("%s thousand ", ones[digit-1]);
		else if( power10 == 100 && digit != 0 )
			printf("%s hundred ", ones[digit-1]);
		else if( power10 == 10 && digit != 0 )
		{
			if( digit == 1 )
			{
				number % 10 != 0 ? printf("%s", teen[(number % 10)-1]) : printf("%s", tens[digit-1]);
				power10 = 0;
				break;
			}
			else
				printf("%s ", tens[digit-1]);
		}
		power10 = power10 / 10;
	}	
	if( power10 != 0 )
		number % 10 != 0 ? printf("%s", ones[number%10 - 1]) : printf("\n") ;
	return 0;
}
