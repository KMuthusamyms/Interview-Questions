5. Given a two dimensional array of string like

  <”luke”, “shaw”>
  <”wayne”, “rooney”>
  <”rooney”, “ronaldo”>
  <”shaw”, “rooney”> 

Where the first string is “child”, second string is “Father”. And given “ronaldo” we have to find his no of grandchildren 
Here “ronaldo” has 3 grandchildren. So our output should be 3.

Code:
#include<stdio.h>
#define MAX 20
struct node
{
	char child[MAX];
	char father[MAX];
};
int countChildren(struct node *arr,char *str,int num)
{
	int ind1,count=0;
	for(ind1=0;ind1<num;ind1++)
		if(strcmp(str,arr[ind1].father)==0)
			count=count+countChildren(arr,arr[ind1].child,num)+1;
	return count;
}
int main()
{
	int num,ind,count=0;
	char string[MAX];
	scanf("%d",&num);
	struct node arr[num];
	for(ind=0;ind<num;ind++)
	{
		scanf("%s",arr[ind].child);
		scanf("%s",arr[ind].father);
	}
	scanf("%s",string);
	for(ind=0;ind<num;ind++)
	{
		if(strcmp(string,arr[ind].father)==0)
			count=count+countChildren(arr,arr[ind].child,num);
	}
	printf("%s has %d grand children",string,count);
	return 0;
}
