A) Alternate sorting: Given an array of integers, rearrange the array in such a way that the first element is first maximum and second element is first minimum.

    Eg.) Input  : {1, 2, 3, 4, 5, 6, 7}
         Output : {7, 1, 6, 2, 5, 3, 4} 

Code:
(i)with extra space
#include<stdio.h>
#define MAX 20
int main()
{
	int num,arr[MAX],res[MAX],ind1,ind2,ind3;
	scanf("%d",&num);
	for(ind1=0;ind1<num;ind1++)
		scanf("%d",&arr[ind1]);
	for(ind1=0,ind2=num-1,ind3=0;ind1<=ind2;ind1++,ind2--)
	{
		if(ind1==ind2)
		{
			res[ind3]=arr[ind1];
			break;
		}
		res[ind3++]=arr[ind2];
		res[ind3++]=arr[ind1];
	}
	for(ind1=0;ind1<num;ind1++)
		printf("%d ",res[ind1]);
	return 0;
}
(ii)without extra space
#include<stdio.h>
#define MAX 1000
int main()
{
	int num,arr[MAX],front,rear,max_ele,ind;
	scanf("%d",&num);
	for(ind=0;ind<num;ind++)
		scanf("%d",&arr[ind]);
	for(front=0,rear=num-1,max_ele=arr[rear]+1,ind=0;ind<num;ind++)
	{
		if(ind%2==0)
		{
			arr[ind] = arr[ind] + ( arr[rear] % max_ele ) * max_ele;
			rear--;
		}
		else
		{
			arr[ind] = arr[ind] + ( arr[front] % max_ele ) * max_ele;
			front++;
		}
	}
	for(ind=0;ind<num;ind++)
		printf("%d ",arr[ind]/max_ele);
	return 0;
}
