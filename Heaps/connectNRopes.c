#include<stdio.h>
#include<stdlib.h>
void minHeapify(int *arr,int ind,int num)
{
	int left, right, smallest, temp;
	left = 2 * ind + 1;
	right = 2 * ind + 2;
	if( left <= num && arr[left] < arr[ind] )
		smallest = left;
	else
		smallest = ind;
	if( right <= num && arr[right] < arr[smallest] )
		smallest = right;
	if( smallest != ind )
	{
		temp = arr[ind];
		arr[ind] = arr[smallest];
		arr[smallest] = temp;
		minHeapify(arr,smallest,num);
	}
}
void buildMinHeap(int *arr,int num)
{
	int ind;
	for( ind = num / 2 ; ind >= 0 ; ind-- )
		minHeapify(arr,ind,num);
}
int extractMin(int *arr,int *num)
{
	int min;
	if( *num - 1 < 0 )
		return 0;
	min = arr[0];
	arr[0] = arr[*num-1];
	*num = *num - 1;
	minHeapify(arr,0,*num-1);
	return min;
}
void heapInsert(int *arr,int *num,int val)
{
	int ind, temp;
	arr[*num] = val;
	ind = *num;
	*num = *num + 1;
	while( arr[ind] < arr[(ind-1)/2] && ind > 0 )
	{
		temp = arr[ind];
		arr[ind] = arr[(ind-1)/2];
		arr[(ind-1)/2] = temp;
		ind = ( ind - 1) / 2;
	}
}
int main()
{
	int num, *ropes, ind, cost = 0, min1, min2, x = 3;
	scanf("%d", &num);
	ropes=(int*)malloc(sizeof(int)*num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d", &ropes[ind]);
	buildMinHeap(ropes,num-1);
	while( 1 )
	{
		min1 = extractMin(ropes,&num);
		min2 = extractMin(ropes,&num);
		cost = cost + min1 + min2;
		if( num == 0 )
			break;
		heapInsert(ropes,&num,min1+min2);
	}
	printf("Minimum Cost : %d", cost);
	return 0;
}
