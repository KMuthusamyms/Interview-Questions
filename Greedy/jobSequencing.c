/*Job Sequencing Problem
Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline.
It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1 How to 
maximize total profit if only one job can be scheduled at a time.
Input: Four Jobs with following 
deadlines and profits
JobID  Deadline  Profit
  a      4        20   
  b      1        10
  c      1        40  
  d      1        30
Output: Following is maximum 
profit sequence of jobs
        c, a   
*/
#include<stdio.h>
struct job
{
	int jobID;
	int deadline;
	int profit;
};
void insertionSort(struct job *arr, int num)
{
	int ind1, ind2;
	struct job temp;
	for( ind1 = 1 ; ind1 < num ; ind1++ )
	{
		ind2 = ind1 - 1;
		temp = arr[ind1];
		while( ind2 >= 0 && arr[ind2].profit < temp.profit )
		{
			arr[ind2+1] = arr[ind2];
			ind2 = ind2 - 1;
		}
		arr[ind2+1] = temp;
	}
}
int* jobSequencing(struct job *arr, int num, int maxi)
{
	int *arr_j, ind1, ind2;
	arr_j = (int*)calloc(sizeof(int), (maxi+1));
	for( ind1 = 0 ; ind1 < maxi ; ind1++ )
	{
		for( ind2 = arr[ind1].deadline ; ind2 >= 1 ; ind2-- )
			if( arr_j[ind2] == 0 )
			{
				arr_j[ind2] = arr[ind1].jobID;
				break;
			}
	}
	return arr_j;
}
int main()
{
	int num, ind, *res_arr, maxi;
	struct job *arr;
	scanf("%d", &num);
	arr = (struct job*)malloc(sizeof(struct job)*num);
	for( ind = 0 ; ind < num ; arr[ind].jobID = ind + 1, ind++ )
		scanf("%d%d", &arr[ind].deadline, &arr[ind].profit);
	insertionSort(arr,num);
	for( ind = 1, maxi = arr[0].deadline ; ind < num ; ind++ )
		if( arr[ind].deadline > maxi )
			maxi = arr[ind].deadline;
	res_arr = jobSequencing(arr,num,maxi);
	for( ind = 1 ; ind <= maxi ; ind++ )
		printf("%d\t",res_arr[ind]);
	return 0;
}
