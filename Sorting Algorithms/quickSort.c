/*
Time Complexity : max( O(nlogn), O(n^2) ) ==> ( pivot divides into two equal lists, pivot divides into an empty and a n-1 list )
Space Complexity: max( O(logn), O(n) )
Inplace algorithm
Unstable sorting technique where relative ordering of elements is altered
*/
#include<stdio.h>
#include<stdlib.h>
int partition(int *arr,int low,int high)
{
	int ind1, ind2, pivot, temp;
	ind1 = low - 1;
	pivot = arr[high];
	for( ind2 = low ; ind2 < high ; ind2++ )
	{
		if( arr[ind2] <= pivot )
		{
			ind1 = ind1 + 1;
			temp = arr[ind1];
			arr[ind1] = arr[ind2];
			arr[ind2] = temp;
		}
	}
	temp = arr[ind1+1];
	arr[ind1+1] = arr[high];
	arr[high] = temp;
	return ind1+1;
}
void quickSort(int *arr,int low,int high)
{
	int p;
	if( low < high )
	{
		p = partition(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}
int main()
{
	int num, *arr, ind;
	scanf("%d", &num);
	arr=(int*)malloc(sizeof(int)*num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d", &arr[ind]);
	quickSort(arr,0,num-1);
	for( ind = 0 ; ind < num ; printf("%d ", arr[ind++]));
	return 0;
}
