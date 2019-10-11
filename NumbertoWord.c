// Convert the given number to word
Range : 0 to 9999
Code:
#include<stdio.h>
#define SIZE 10
int placeValue(int num)
{
	int power = 1;
	while( num / power )
		power = power * 10;
	return power / 10;
}
int main()
{
	char ones[][SIZE] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char tens[][SIZE] = { "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	int number, index, power, digit;
	scanf("%d",&number);
	power = placeValue( number );
	while( number != number / power )
	{
		digit = ( number / power ) % 10;
		if ( digit != 0 && power == 1000)
		{
			printf("%s thousand ", ones[digit-1]);
			power = power / 10;
		}
		else if( digit != 0 && power == 100)
		{
			printf("%s hundred ", ones[digit-1]);
			power = power / 10;
		}
		else if ( digit != 0 && power == 10)
		{
			printf("%s ", tens[digit-1]);
			power = power / 10;
		}
		else
			power = power / 10;
	}
	digit = number % 10;
	if( digit != 0 )
		printf("%s", ones[digit-1]);
	return 0;
}
