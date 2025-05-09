/*this code implements linear search in a string*/
#include<stdio.h>
#include<string.h>
void linear_srch(char item[20],char letter)
{	int n=strlen(item);
	for(int i=0;i<n;i++)
	{
		if (item[i]==letter)
		{
			printf("item found at %d\n",i+1);
			return;
		}
	}
	printf("not found");
}
int main()
{	char str[20],letter;
	printf("enter string:");
	scanf("%s",str);
	getchar();
	printf("enter letter to be found:");
	scanf("%c",&letter);
	linear_srch(str,letter);
	return 0;
}
