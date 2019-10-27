/*
Time complexity : O(nlogn)
Space complexity: O(logn)
Inplace Algorithm
Unstable sorting technique which changes the relative ordering of elements
*/
#include<stdio.h>
#include<stdlib.h>
void maxHeapify(int *arr,int ind,int num)
{
	int left, right, temp, largest;
	left = 2 * ind + 1;
	right = 2 * ind + 2;
	if( left <= num && arr[left] > arr[ind] )
		largest = left;
	else
		largest = ind;
	if( right <= num && arr[right] > arr[largest] )
		largest = right;
	if( largest != ind )
	{
		temp = arr[ind];
		arr[ind] = arr[largest];
		arr[largest] = temp;
		maxHeapify(arr,largest,num);
	}
}
void buildMaxHeap(int *arr,int num)
{
	int ind;
	for( ind = num / 2 ; ind >= 0 ; ind-- )
		maxHeapify(arr,ind,num);
}
void heapSort(int *arr,int num)
{
	int ind, temp;
	buildMaxHeap(arr,num);
	for( ind = num ; ind > 0 ; ind-- )
	{
		temp = arr[0];
		arr[0] = arr[num];
		arr[num] = temp;
		num = num - 1;
		maxHeapify(arr,0,num);
	}	
}
int main()
{
	int num, *arr, ind;
	scanf("%d", &num);
	arr=(int*)malloc(sizeof(int)*num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d", &arr[ind]);
	heapSort(arr,num-1);
	for( ind = 0 ; ind < num ; printf("%d ", arr[ind++]));
	return 0;
}
