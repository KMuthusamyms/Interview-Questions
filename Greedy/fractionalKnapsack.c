#include<stdio.h>
struct FKS
{
	int obId;
	int profit;
	int weight;
	float pByw;
};
void insertionSort(struct FKS *arr, int num)
{
	int ind1, ind2;
	struct FKS temp;
	for( ind1 = 1 ; ind1 < num ; ind1++ )
	{
		ind2 = ind1 - 1;
		temp = arr[ind1];
		while( ind2 >= 0 && arr[ind2].pByw < temp.pByw )
		{
			arr[ind2+1] = arr[ind2];
			ind2 = ind2 - 1;
		}
		arr[ind2+1] = temp;
	}
}
float fractionalKnapsack( struct FKS *arr, int num, int capacity )
{
	int ind;
	float maxPro = 0.0 ;
	for( ind = 0 ; ind < num ; ind++ )
	{
		if( capacity > 0 && arr[ind].weight < capacity )
		{
			capacity = capacity - arr[ind].weight;
			maxPro = maxPro + arr[ind].profit;
		}
		else 
			break;
	}
	if( capacity > 0 )
		maxPro = maxPro + arr[ind].pByw * capacity ;
	return maxPro;
}
int main()
{
	int num, ind, capacity;
	float Profit;
	struct FKS *arr;
	scanf("%d%d", &num, &capacity);
	arr = (struct FKS*)malloc(sizeof(struct FKS)*num);
	for( ind = 0 ; ind < num ; ind++ )
		scanf("%d%d%d", &arr[ind].obId, &arr[ind].profit, &arr[ind].weight);
	for( ind = 0 ; ind < num ; ind++ )
		arr[ind].pByw = arr[ind].profit / ( arr[ind].weight * 1.0 );
	insertionSort(arr,num);
	Profit = fractionalKnapsack(arr,num,capacity);
	printf("Maximum profit is %f", Profit);
	return 0;
}
