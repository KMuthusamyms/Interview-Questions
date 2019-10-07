Given a set of numbers like <10, 36, 54,89,12> we want to find sum of weights based on the following conditions
    1. 5 if a perfect square
    2. 4 if multiple of 4 and divisible by 6
    3. 3 if even number

And sort the numbers based on the weight and print it as follows

<10,its_weight>,<36,its weight><89,its weight>

Should display the numbers based on increasing order.

Code:
#include<stdio.h>
struct node
{
	int number;
	int weight;
};
int isPerfect(int num)
{
	int ind;
	for(ind=1;ind<=num/2;ind++)
		if(ind*ind==num)
			return 1;
	return 0;
}
void computeWeight(struct node *arr,int num)
{
	int ind1;
	for(ind1=0;ind1<num;ind1++)
	{
		if(isPerfect(arr[ind1].number))
			arr[ind1].weight=arr[ind1].weight+5;
		if(arr[ind1].number%4==0 && arr[ind1].number%6==0)
			arr[ind1].weight=arr[ind1].weight+4;
		if(arr[ind1].number%2==0)
			arr[ind1].weight=arr[ind1].weight+3;
	}
}
void insertionSort(struct node *arr,int num)
{
	int ind1,ind2;
	struct node temp;
	for(ind1=1;ind1<num;ind1++)
	{
		ind2=ind1-1;
		temp=arr[ind1];
		while(ind2>=0 && arr[ind2].weight<temp.weight)
		{
			arr[ind2+1]=arr[ind2];
			ind2=ind2-1;
		}
		arr[ind2+1]=temp;
	}
}
int main()
{
	int num,ind1;
	scanf("%d",&num);
	struct node arr[num];
	for(ind1=0;ind1<num;arr[ind1].weight=0,ind1++)
		scanf("%d",&arr[ind1].number);
	computeWeight(arr,num);
	insertionSort(arr,num);
	for(ind1=0;ind1<num;ind1++)
		printf("%d - %d\n",arr[ind1].number,arr[ind1].weight);
	return 0;
}
