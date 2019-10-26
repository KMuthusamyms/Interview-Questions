/* 
Time Complexity : O(n^2)
Space Complexity: O(1)
Stable sorting algorithm as it preserves the relative ordering of the elements
*/
#include<stdio.h>
void insertionSort( int *arr, int num )
{
	int ind1, ind2, temp;
	for( ind1 = 1 ; ind1 < num ; ind1++ )
	{
		ind2 = ind1 - 1;
		temp = arr[ind1];
		while( ind2 >= 0 && temp < arr[ind2] )
		{
			arr[ind2+1] = arr[ind2];
			ind2 = ind2 - 1;
		}
		arr[ind2+1] = temp;
	}
}
int main()
{
	int num, *arr, ind;
	scanf("%d", &num);
	arr = (int*) malloc( sizeof(int) * num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d", &arr[ind]);
	insertionSort(arr,num);
	for( ind = 0 ; ind < num ; printf("%d ", arr[ind++]));
	return 0;
}
