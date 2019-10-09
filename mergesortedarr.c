Given two sorted arrays, merge them such that the elements are not repeated

Eg 1: Input:
        Array 1: 2,4,5,6,7,9,10,13
        Array 2: 2,3,4,5,6,7,8,9,11,15
       Output:
       Merged array: 2,3,4,5,6,7,8,9,10,11,13,15
   
Code:
#include<stdio.h>
void Union(int num1,int *arr1,int num2,int *arr2,int *arr,int *end)
{
	int ind,ind1,ind2;
	for(ind=0,ind1=0,ind2=0;ind1<num1 && ind2<num2;)
	{
		if(arr1[ind1]<arr2[ind2])
			arr[ind++]=arr1[ind1++];
		else if(arr1[ind1]>arr2[ind2])
			arr[ind++]=arr2[ind2++];
		else
		{
			arr[ind++]=arr1[ind1++];
			ind2++;
		}
	}
	for(;ind1<num1;arr[ind++]=arr1[ind1++]);
	for(;ind2<num2;arr[ind++]=arr2[ind2++]);
	*end=ind;
}
int main()
{
	int num1,num2,ind,end;
	int *arr1,*arr2,*arr;
	scanf("%d%d",&num1,&num2);
	arr1=(int*)malloc(sizeof(int)*num1);
	arr2=(int*)malloc(sizeof(int)*num2);
	arr=(int*)malloc(sizeof(int)*(num1+num2));
	for(ind=0;ind<num1;ind++)
		scanf("%d",&arr1[ind]);
	for(ind=0;ind<num2;ind++)
		scanf("%d",&arr2[ind]);
	Union(num1,arr1,num2,arr2,arr,&end);
	for(ind=0;ind<end;ind++)
		printf("%d ",arr[ind]);
	return 0;
}
