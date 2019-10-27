/*
Time Complexity : O(n^2)
Space Complexity: O(1)
(In n-1 passes n-1 elements come to their correct position and the last element automatically comes to its correct position-so n-1 passes)
*/
#include<stdio.h>
void selectionSort(int *arr,int num)
{
	int ind1, ind2, min, temp;
	for( ind1 = 0 ; ind1 < num - 1 ; ind1++ )
	{
		min = ind1;
		for( ind2 = ind1 + 1 ; ind2 < num ; ind2++ )
			if( arr[ind2] < arr[min] )
				min = ind2;
		if( min != ind1 )
		{
			temp = arr[ind1];
			arr[ind1] = arr[min];
			arr[min] = temp;
		}
	}
}
int main()
{
	int num, *arr, ind;
	scanf("%d", &num);
	arr=(int*)malloc(sizeof(int)*num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d", &arr[ind]);
	selectionSort(arr,num);
	for( ind = 0 ; ind < num ; printf("%d ", arr[ind++]));
	return 0;
}
