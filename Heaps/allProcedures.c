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
		return -1;
	max = arr[0];
	arr[0] = arr[*num-1];
	*num = *num - 1;
	maxHeapify(arr,0,*num-1);
	return max;
}
void heapIncreaseKey(int *arr,int ind,int val,int num)
{
	int temp;
	if( arr[ind] > val )
		printf("Error");
	arr[ind] = val;
	while( ind > 0 )
	{
		if( arr[ind] > arr[ind/2] )
		{
			temp = arr[ind];
			arr[ind] = arr[ind/2];
			arr[ind/2] = temp;
		}
		else
			break;
	}
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
void printHeap(int *arr,int num)
{
	int ind;
	for( ind = 0 ; ind < num ; ind++ )
		printf("%d ", arr[ind]);
}
int main()
{
	int num, *arr, ind, maxi, key, value;
	scanf("%d", &num);
	arr=(int*)malloc(sizeof(int)*num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d", &arr[ind]);
	heapSort(arr,num-1);
	printf("Increasing Order : ");	
	printHeap(arr,num);
	buildMaxHeap(arr,num-1);
	maxi = extractMax(arr,&num);
	printf("\nMaximum Element in Heap : %d", maxi);
	printf("\nAfter Deletion in sorted order : ");
	heapSort(arr,num-1);
	printHeap(arr,num);
	buildMaxHeap(arr,num-1);
	printf("\nEnter the key which you want to increase : ");
	scanf("%d", &key);
	for( ind = 0 ; ind < num ; ind++ )
		if( arr[ind] == key )
			break;
	printf("\nEnter the increased key value : ");
	scanf("%d", &value);
	heapIncreaseKey(arr,ind,value,num-1);
	heapSort(arr,num-1);
	printHeap(arr,num);
	return 0;
}
