/*
Time Complexity : O(n^2)
Space Complexity: O(1)
Stable sorting which does not alter the relative ordering od elements
Inplace
keynote: we should check if all the elements pairwise are in their correct relative position(small left big right)
An air bubble left in the water comes to the top similarly here largest elements comes to the top
*/
#include<stdio.h>
void bubbleSort(int *arr,int num)
{
	int ind1, ind2, swapped, temp;
	for( ind1 = 0 ; ind1 < num ; ind1++ )
	{
		swapped = 0;
		for( ind2 = 0 ; ind2 < num - ind1 - 1 ; ind2++ )
		{
			if( arr[ind2] > arr[ind2+1])
			{
				temp = arr[ind2];
				arr[ind2] = arr[ind2+1];
				arr[ind2+1] = temp;
				swapped = 1;
			}
			if( swapped == 0 )
				break;
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
	bubbleSort(arr,num);
	for( ind = 0 ; ind < num ; printf("%d ", arr[ind++]));
	return 0;
}
