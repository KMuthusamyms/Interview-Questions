Move through the matrix for a range of queries in four directions
Code:
#include<stdio.h>
#include<string.h>
#define MAX 100
int main()
{
	int sq_mat_size,mat[MAX][MAX],ind1,ind2,queries,location=0;
	char direction[MAX];
	scanf("%d",&sq_mat_size);
	for(ind1=1;ind1<=sq_mat_size;ind1++)
	{
		for(ind2=1;ind2<=sq_mat_size;ind2++)
			scanf("%d",&mat[ind1][ind2]);
	}
	scanf("%d",&queries);
	ind1=ind2=1;
	while(queries--)
	{
		scanf("%s",direction);
		if(strcmp(direction,"RIGHT")==0)
		{
			if(ind2+1<=sq_mat_size)
			{
				ind2++;
				location=mat[ind1][ind2];
			}
		}
		else if(strcmp(direction,"LEFT")==0)
		{
			if(ind2-1>=1)
			{
				ind2--;
				location=mat[ind1][ind2];
			}
		}
		else if(strcmp(direction,"UP")==0)
		{
			if(ind1-1>=1)
			{
				ind1--;
				location=mat[ind1][ind2];
			}
		}
		else
		{
			if(ind1+1<=sq_mat_size)
			{
				ind1++;
				location=mat[ind1][ind2];
			}
		}
	}
	printf("%d",location);
	return 0;
}
