Write a program to give the following output for the given input

Eg 1: Input: a1b10
       Output: abbbbbbbbbb
Eg: 2: Input: b3c6d15
          Output: bbbccccccddddddddddddddd
The number varies from 0 to INT_MAX

Code:
#include<iostream>
using namespace std;
#define MAX 30
int main()
{
	char string[MAX], p_char;
	int p_count = 0, index;
	cin >> string;
	for( index = 0 ; string[index] ; index++ )
	{
		if( string[index] >= 'a' && string[index] <= 'z' && p_count == 0 )
			p_char = string[index];
		else if( string[index] >= 'a' && string[index] <= 'z' && p_count != 0 )
		{
			for( ; p_count ; cout << p_char, p_count = p_count - 1 );
			p_char = string[index];
			p_count = 0;
		}
		else
			p_count = p_count * 10 + ( string[index] - '0' );
	}
	while( p_count-- )
		cout << p_char;
	return 0;
}
