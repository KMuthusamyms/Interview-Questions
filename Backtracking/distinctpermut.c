#include<stdio.h>
#include<string.h>
#define MAX 20
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permutations(char *str, int start, int end)
{
	int index, index2, flag;
	if( start == end )
		printf("%s\n", str);
	else
	{
		for( index = start ; index <= end ; index++ )
		{
			for( index2 = start, flag = 1 ; index2 < index ; index2++ )
				if( str[index2] == str[index] )
					flag = 0;
			if( flag )
			{
				swap(&str[start],&str[index]);
				permutations(str,start+1,end);
				swap(&str[start],&str[index]);
			}
		}
	}
}
int main()
{
	char string[MAX];
	scanf("%s", string);
	permutations(string,0,strlen(string)-1);
	return 0;
}
