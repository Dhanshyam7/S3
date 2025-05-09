/*This file implements a code to check if the given string is a palindrome using stack. */
#include<stdio.h>
#include<string.h>
int s[20],top=-1;
void push(char item)
{
        top++;
        s[top]=item;
}
void check(char str[20])
{
	int i,n=strlen(str);
	for(i=0;i<n/2;i++)
	{
		push(str[n-i-1]);
		if (str[i]!=s[i])
			break;
	}
	if (i==n/2)
		printf("palindrome\n");
	else
		printf("not palindrome\n");
}
int main()
{	char str[20];
	printf("enter string:");
	scanf("%s",str);
	check(str);
}

