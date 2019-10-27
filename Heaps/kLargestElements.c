/*
Time Complexity : O(K logn)
Space Complexity: O(logn) for recursive stack
*/
#include<stdio.h>
#include<stdlib.h>
void maxHeapify(int *arr,int ind,int num)
{
	int left, right, largest, temp;
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
int extractMax(int *arr,int *num)
{
	int max;
	if( *num - 1 < 0 )
	{
		printf("Heap Underflow");
		return -1;
	}
	max = arr[0];
	arr[0] = arr[*num - 1];
	*num = *num - 1;
	maxHeapify(arr,0,*num-1);
	return max;
}
int main()
{
	int num, *arr, ind, K;
	scanf("%d%d", &num, &K);
	arr=(int*)malloc(sizeof(int)*num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d", &arr[ind]);
	buildMaxHeap(arr,num-1);
	printf("The %d largest elements are : ", K);
	for( ind = 0 ; ind < K ; ind++ )
		printf("%d ", extractMax(arr,&num));
	return 0;
}
