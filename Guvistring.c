#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int main()
{
	char string1[MAX], string2[MAX];
	int ind, flag = 0, hash[256] = {0};
	scanf("%[^\n]s",string1);
	fflush(stdin);
	scanf("%[^\n]s",string2);
	for( ind = 0 ; string2[ind] ; ind++ )
			hash[string2[ind]]+=1;
	for( ind = 0 ; string1[ind] ; ind++ )
	{
		if( hash[string1[ind]] != 0 && string1[ind] != ' ')
		{
			printf("%c",string1[ind]);
			flag = 1;
			hash[string1[ind]]-=1;
		}
	}
	if( flag = 0 )
		printf("-1");
	return 0;
}
