Find if a String2 is substring of String1. If it is, return the index of the first occurrence. else return -1.

Eg 1:Input:
        String 1: test123string
         String 2: 123
        Output: 4
Eg 2: Input:
        String 1: testing12
        String 2: 1234 
        Output: -1
Code:
// Implementation of strstr() function
#include<stdio.h>
#define MAX 20
int strstr(char *string1,char *string2)
{
	int ind1,ind2,temp;
	for(ind1=0;string1[ind1];ind1=temp,ind1++)
	{
		for(ind2=0,temp=ind1;string1[ind1]==string2[ind2] && string2[ind2];ind1++,ind2++);
		if(string2[ind2]=='\0')
			return temp;
	}
	return -1;
}
int main()
{
	char string1[MAX],string2[MAX];
	int index;
	scanf("%s%s",string1,string2);
	index = strstr(string1,string2);
	printf("%d",index);
	return 0;
}
