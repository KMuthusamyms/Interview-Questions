Find minimum number of currency notes and values that sum to given amount
Given an amount, find the minimum number of notes of different denominations that sum upto the given amount. Starting from the highest denomination note, try to accommodate as many notes possible for given amount.

We may assume that we have infinite supply of notes of values {2000, 500, 200, 100, 50, 20, 10, 5, 1}

Code:
#include<stdio.h>
int currency[] = { 2000,500,200,100,50,20,5,1 };
int main()
{
	int amount, notes, ind=0;
	scanf("%d",&amount);
	printf("Currency Count ");
	while(amount!=0)
	{
		notes = amount / currency[ind];
		amount = amount % currency[ind];
		if(notes > 0)
			printf("\n%d	: %d",currency[ind],notes);
		ind+=1;
	}
	return 0;
}
