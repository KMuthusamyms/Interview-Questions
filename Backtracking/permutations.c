#include<stdio.h>
#include<string.h>
#define MAX 20
void swap(char *x,char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void permutations(char *str,int start,int end)
{
	int index;
	if( start == end )
		printf("%s\n", str);
	else
	{
		for( index = start ; index <= end ; index++ )
		{
			swap(&str[start],&str[index]);
			permutations(str,start+1,end);
			swap(&str[index],&str[start]);
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
