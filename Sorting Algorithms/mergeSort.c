/*
Time Complexity : O(nlogn)
Space Complexity: O(n) ===== > ( merge procedure - O(n) for global array and for mergesort recursion stack - O(logn) )
Out of place algorithm
Stable sorting technique as it preserves relative ordering of elements
best case = worst case => Average case
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void merge(int *arr,int low,int mid,int high)
{
	int N1, N2, ind1, ind2, ind3, *L, *R;
	N1 = mid - low + 1;
	N2 = high - mid;
	L = (int*)malloc(sizeof(int)*(N1+1));
	R = (int*)malloc(sizeof(int)*(N2+1));
	for( ind1 = 0 ; ind1 < N1 ; ind1++ )
		L[ind1] = arr[low+ind1];
	for( ind2 = 0 ; ind2 < N2 ; ind2++ )
		R[ind2] = arr[mid+ind2+1];
	L[N1] = INT_MAX;
	R[N2] = INT_MAX;
	for( ind1 = 0, ind2 = 0, ind3 = low ; ind3 <= high ; ind3++ )
	{
		if( L[ind1] <= R[ind2] )
		{
			arr[ind3] = L[ind1];
			ind1++;
		}
		else
		{
			arr[ind3] = R[ind2];
			ind2++;
		}
	}
	free(L);
	free(R);
}
void mergeSort(int *arr,int low,int high)
{
	int mid;
	if( low < high )
	{
		mid = ( low + high ) / 2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
int main()
{
	int num, *arr, ind;
	scanf("%d", &num);
	arr=(int*)malloc(sizeof(int)*num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d", &arr[ind]);
	mergeSort(arr,0,num-1);
	for( ind = 0 ; ind < num ; printf("%d ", arr[ind++]));
	return 0;
}
