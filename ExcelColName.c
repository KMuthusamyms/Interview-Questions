Find Excel column name from a given column number
MS Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB ….. etc. In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA”.
Given a column number, find its corresponding Excel column name. Following are more examples.

Input          Output
 26             Z
 51             AY
 52             AZ
 80             CB
 676            YZ
 702            ZZ
 705            AAC
 
 Code:
#include<stdio.h>
#define MAX 5
void reverse( char* string, int start, int end )
{
	char temp;
	for( ; start < end ; start++, end-- )
	{
		temp = string[start];
		string[start] = string[end];
		string[end] = temp;
	}
}
int main()
{
	int number, digit, power26, ind;
	char string[MAX], ch;
	scanf("%d", &number);
	power26 = 26;
	ind = 0;
	while( number != 0 )
	{
		digit = number % power26;
		if( digit != 0 )
		{
			number = number / power26;
			string[ind++] = 'A'+digit-1;
		}
		else
		{
			number = number / power26 - 1;
			string[ind++] = 'Z';
		}
	}
	string[ind] = '\0';
	reverse( string, 0, ind-1 );
	printf("%s", string);
	return 0;
}
