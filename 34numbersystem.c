C) Form a number system with only 3 and 4. Find the nth number of the number system.
Eg.) The numbers are: 3, 4, 33, 34, 43, 44, 333, 334, 343, 344, 433, 434, 443, 444, 3333, 3334, 3343, 3344, 3433, 
3434, 3443, 3444 ….

Code:
#include<stdio.h>
#define THREE 3
#define FOUR 4
int pow(int n,int x)
{
	int prod=1;
	while(x--)
	{
		prod=prod*n;
	}
	return prod;
}
int calculatePower(int n)
{
	int ind,power=1;
	for(ind=1;ind<n;ind++)
	{
		if(n>=pow(2,ind)-1 && n<=pow(2,ind+1)-2)
		{
			power=ind;
			break;
		}
	}
	return power;
}
int main()
{
	int n,digit,low_lim,upp_lim,range,diff,term=0;
	scanf("%d",&n);
	digit=calculatePower(n);
	while(digit!=0)
	{
		low_lim=pow(2,digit)-1;
		upp_lim=pow(2,digit+1)-2;
		range=upp_lim-(low_lim-1);
		diff=n-(low_lim-1);
		if(diff<=range/2)
		{
			term=term+THREE*pow(10,digit-1);
			n=n-range/2;
		}
		else
		{
			term=term+FOUR*pow(10,digit-1);
			n=n-range;
		}
		digit=digit-1;
	}	
	printf("%d\n",term);
	return 0;
}
