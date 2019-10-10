Given bigger NxN matrix and a smaller MxM matrix print TRUE if the smaller matrix 
can be found in the bigger matrix else print FALSE

Code:
#include<stdio.h>
#define MAX 50
int main()
{
	int a[MAX][MAX],b[MAX][MAX],r1,c1,r2,c2,i,j,k,l;
	scanf("%d%d",&r1,&c1);
	for(i=0;i<r1;i++)
		for(j=0;j<c1;j++)
			scanf("%d",&a[i][j]);
	scanf("%d%d",&r2,&c2);
	for(i=0;i<r2;i++)
		for(j=0;j<c2;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<r1;i++)
		for(j=0;j<c1;j++)
		{
 			if(a[i][j]==b[0][0])
 			{	 
   				for(k=0;k<r2;k++)
    				for(l=0;l<c2;l++)
      					if(a[i+k][j+l]!=b[k][l])
        					goto EXIT;
    			EXIT:
    			if(k==r2 && l==c2)
    			{	  
       				printf("\nTRUE : <%d,%d> to <%d,%d>\n",i,j,i+k-1,j+l-1);
       				return;
    			}
 			}
		}
 	printf("\n False\n");
 	return 0;
}
