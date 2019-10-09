Using Recursion reverse the string such as

Eg 1: Input: one two three
      Output: three two one
Eg 2: Input: I love india
      Output: india love I 
Code:
#include<stdio.h>
#define MAX 30
void iterReverse(char *string,int first,int last)
{
	char temp;
	for(;first<last;first++,last--)
	{
		temp=string[first];
		string[first]=string[last];
		string[last]=temp;
	}
}
void recursiveReverse(char *string,int first,int last)
{
	char temp;
	if(first>=last)
		return;
	temp=string[first];
	string[first]=string[last];
	string[last]=temp;
	recursiveReverse(string,first+1,last-1);
}
int main()
{
	char string[MAX];
	int len,ind1,ind2;
	scanf("%[^\n]s",string);
	for(len=0;string[len];len++);
	reverse(string,0,len-1);
	for(ind1=0,ind2=0;string[ind2];ind2++)
		if(string[ind2]==' ')
		{
			reverse(string,ind1,ind2-1);
			ind1=ind2+1;
		}
	recursiveReverse(string,ind1,len-1);
	printf("%s",string);
	return 0;
}
