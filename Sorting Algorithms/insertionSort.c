/* 
Time Complexity : O(n^2)
Space Complexity: O(1)
for sorting n elements we require n-1 comparisions and n-1 movments, so we might think that by using binary search we can reduce the 
number of comparisions to log n but number of movments still remain O(n), we might also think that by using doubly linked list we
can reduce the number of movments to O(1) but number of comparisions remains same in this case. So, either by using binary search or
by using doubly linked list we might ntot be able to reduce the time complexity.So, the time complexity is O(n^2).
Inplace algorithm as it does not require any extra space
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
