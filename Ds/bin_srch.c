/*this code implements a code to search element in the given sorted set of integers using binary search algorithm*/
#include<stdio.h>
void binary_srch(int arr[10],int n,int len)
{
	int low=0,high=len-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if (arr[mid]==n)
		{	printf("element found at %d\n",mid+1);
			return;
		}
		else if (arr[mid]>n)
			high=mid-1;
		else
			low=mid+1;
	}
printf("not found\n");
}
int main()
{	int arr[10],n,len;
	printf("enter number of elements");
	scanf("%d",&len);
	printf("enter elements:\n");
	for(int i=0;i<len;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter element to be found:");
	scanf("%d",&n);
	binary_srch(arr,n,len);
}
