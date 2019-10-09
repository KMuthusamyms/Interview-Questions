2. Write a program to sort the elements in odd positions in descending order and elements in ascending order

Eg 1: Input: 13,2 4,15,12,10,5
        Output: 13,2,12,10,5,15,4
Eg 2: Input: 1,2,3,4,5,6,7,8,9
        Output: 9,2,7,4,5,6,3,8,1 
Code:
// I applied insertion sort but apply heap sort so that time complexity will be reduced
#include<stdio.h>
#define MAX 30
void insertionSort(int *arr,int num)
{
	int ind1,ind2,temp;
	for(ind1=1;ind1<num;ind1++)
	{
		temp=arr[ind1];
		ind2=ind1-1;
		while(ind2>=0 && temp<arr[ind2])
		{
			arr[ind2+1]=arr[ind2];
			ind2=ind2-1;
		}
		arr[ind2+1]=temp;
	}
}
int main()
{
	int num,arr[MAX],ind,ind1,ind2,ind3,ind4,evenArr[MAX],oddArr[MAX];
	scanf("%d",&num);
	for(ind=0;ind<num;ind++)
		scanf("%d",&arr[ind]);
	for(ind=0,ind1=0,ind2=0;ind<num;ind++)
		if(ind%2==0)
			evenArr[ind1++]=arr[ind];
		else
			oddArr[ind2++]=arr[ind];
	insertionSort(evenArr,ind1);
	insertionSort(oddArr,ind2);
	for(ind=0,ind3=0;ind3<ind1;ind3++,ind+=2)
		arr[ind]=evenArr[ind3];	
	for(ind=1,ind4=ind2-1;ind4>=0;ind4--,ind+=2)
		arr[ind]=oddArr[ind4];
	for(ind=0;ind<num;ind++)
		printf("%d ",arr[ind]);
	return 0;
}
