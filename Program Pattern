Print the word with odd letters as

P         M
 R      A
   O  R
     G
  O    R
 R       A
P          M 

Code:
#include<stdio.h>
#include<string.h>
int main()
{
	char string[] = "PROGRAM";
	int ind1,ind2,len;
	len = strlen(string);
	for(ind1=0;ind1<len;printf("\n"),ind1++)
		for(ind2=0;ind2<len;ind2++)
		{
			if(ind1==ind2)
				printf("%c",string[ind2]);
			else if(ind2==len-(ind1+1))
				printf("%c",string[len-(ind1+1)]);
			else
				printf(" ");
		}
	return 0;
}
