Number of cells a queen can move with obstacles on the chessborad
Consider a N X N chessboard with a Queen and K obstacles. 
The Queen cannot pass through obstacles. Given the position (x, y) of Queen, the task is to find the number of cells the queen can move.

Code:
#include<stdio.h>
#define N 8
int x[] = { -1,-1,-1,0,1,1,1,0 };
int y[] = { -1,0,1,1,1,0,-1,-1 };
int main()
{
	int chess[N][N] = {0};
	int q_xpos, q_ypos, obs, o_xpos, o_ypos, ind1, dir, rd, cd, count=0;
	scanf("%d%d",&q_xpos,&q_ypos);
	scanf("%d",&obs);
	for(ind1=0;ind1<obs;ind1++)
	{
		scanf("%d%d",&o_xpos,&o_ypos);
		chess[o_xpos][o_ypos] = 2;
	}
	for(dir=0;dir<8;dir++)
	{
		rd = q_xpos + x[dir];
		cd = q_ypos + y[dir];
		while(rd>=0 && rd<N && cd>=0 && cd<N)
		{
			if(chess[rd][cd]==2)
				break;
			count+=1;
			rd+=x[dir];
			cd+=y[dir];
		}
	}
	printf("Cells : %d",count);
	return 0;
}
