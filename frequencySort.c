Input : 1 1 1 2 3 3 3 3 4 4 5 5 5 5 5
Output: 5 5 5 5 5 3 3 3 3 1 1 1 4 4 2
Code:
#include<stdio.h>
#define SIZE 100
struct node
{
	int data;
	int frequency;
};
void insertionSort( struct node *arr, int num )
{
	int ind1, ind2;
	struct node temp;
	for( ind1 = 1 ; ind1 < num ; ind1++ )
	{
		temp = arr[ind1];
		ind2 = ind1 - 1;
		while( ind2 >= 0 && arr[ind2].frequency < temp.frequency )
		{
			arr[ind2+1] = arr[ind2];
			ind2--;
		}
		arr[ind2+1] = temp;
	}
}
int main()
{
	char string[SIZE];
	int ind;
	struct node array[10];
	scanf("%[^\n]s",string);
	for(ind=0;ind<=9;array[ind].data=ind,array[ind].frequency=0,ind++);
	for( ind = 0 ; string[ind] ; ind++ )
		if( string[ind] != ' ')
			array[ string[ind] - '0' ].frequency +=1;
	insertionSort( array, 10 );
	for( ind = 0 ; ind <= 9 ; ind++ )
		if( array[ind].frequency != 0 )
			while( array[ind].frequency-- )
				printf("%d ", array[ind].data );
	return 0;
}
