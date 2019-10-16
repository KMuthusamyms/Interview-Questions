Search a Word in a 2D Grid of characters
Given a 2D grid of characters and a word, find all occurrences of given word in grid. A word can be matched in all 8 directions at any point. Word is said be found in a direction if all characters match in this direction (not in zig-zag form).

The 8 directions are, Horizontally Left, Horizontally Right, Vertically Up,Vertically down and 4 Diagonal directions.
Code:
#include<stdio.h>
#include<string.h>
#define R 3
#define C 14
int x[] = { -1,-1,-1,0,1,1,1,0 };
int y[] = { -1,0,1,1,1,0,-1,-1 };
int findWord(char grid[R][C],int row,int col,char word[])
{
	int rd,cd,k,len,dir;
	if(grid[row][col]!=word[0])
		return 0;
	len = strlen(word);
	for(dir=0;dir<8;dir++)
	{
		rd = row + x[dir];
		cd = col + y[dir];
		for(k=1;k<len;k++)
		{
			if(rd<0 || rd>=R || cd<0 || cd>=C)
				break;
			if(grid[rd][cd]!=word[k])
				break;
			rd+=x[dir];
			cd+=y[dir];
		}
		if(k==len)
			return 1;
	}
	return 0;
}
void patternSearch(char grid[R][C],char word[])
{
	int row,col;
	for(row=0;row<R;row++)
		for(col=0;col<C;col++)
			if(findWord(grid,row,col,word))
				printf("%d %d\n",row,col);
}
int main()
{
	char grid[R][C] = { "GEEKSFORGEEKS", 
                        "GEEKSQUIZGEEK", 
                        "IDEQAPRACTICE" };
 	patternSearch(grid,"GEEKS");
 	return 0;
}
