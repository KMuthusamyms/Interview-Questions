4. Given a 9×9 sudoku we have to evaluate it for its correctness. We have to check both the sub matrix correctness and 
the whole sudoku correctness.

Code:
#include<stdio.h>
#define N 9
int main()
{
	int ind1,ind2,ind3,ind4,sudoku[N][N],flag;
	char c;
	for(ind1=0;ind1<N;ind1++)
		for(ind2=0;ind2<N;ind2++)
		{
			scanf("%c",&c);
			sudoku[ind1][ind2] = c-'0';
		}
	//row checking
	for(ind1=0;ind1<N;ind1++)
	{
		flag=0;
		for(ind2=0;ind2<N;ind2++)
			flag = flag | ( 1 << sudoku[ind1][ind2] - 1 );
		if(flag!=511)
		{
			printf("Sudoku is incorrect");
			return 0;
		}
	}
	//column checking
	for(ind1=0;ind1<N;ind1++)
	{
		flag=0;
		for(ind2=0;ind2<N;ind2++)
			flag = flag | ( 1 << sudoku[ind1][ind2] - 1 );
		if(flag!=511)
		{
			printf("Sudoku is incorrect");
			return 0;
		}
	}
	//square checking
	for(ind1=0;ind1<3;ind1++)
		for(ind2=0;ind2<3;ind2++)
		{
			flag=0;
			for(ind3=0;ind3<3;ind3++)
				for(ind4=0;ind4<3;ind4++)
					flag = flag | ( 1 << sudoku[ind1*3+ind3][ind2*3+ind4] - 1);
			if(flag!=511)
			{
				printf("Sudoku is incorrect");
				return 0;
			}
		}
	printf("Sudoku is correct");
	return 0;
}
