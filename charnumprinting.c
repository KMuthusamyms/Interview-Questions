Write a program to give the following output for the given input

Eg 1: Input: a1b10
       Output: abbbbbbbbbb
Eg: 2: Input: b3c6d15
          Output: bbbccccccddddddddddddddd
The number varies from 1 to 99.

Code:
#include<stdio.h>
#define MAX 30
int main()
{
	char str[MAX],alpha;
	int ind,count;
	scanf("%s",str);
	for(ind=0;str[ind];ind++)
	{
		if(str[ind]>='a' && str[ind]<='z')
			alpha = str[ind];
		else if(str[ind]>='0' && str[ind]<='9')
		{
			count = str[ind]-'0';
			if(str[ind+1]>='0' && str[ind+1]<='9')
			{
				count = (str[ind]-'0')*10 + (str[ind+1]-'0');
				ind++;
			}
			while(count--)
				printf("%c",alpha);
		}
	}
	return 0;
}
