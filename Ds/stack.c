/*c file to implement stack data structure. It includes the operations push, pop, display of the stack*/

#include<stdio.h>
#include<stdlib.h>
int  top=-1,s[100];
void push(int size);
void pop();
void display();
void push(int size)
{
    int item;
    if (top==size-1)
        printf("stack overflow\n");
    else
    {
        printf("enter element:");
        scanf("%d",&item);
        top++;
        s[top]=item;
    }
}
void pop()
{   if (top==-1)
    {
        printf("stack underflow\n");
    }
    else
    {   int item=s[top];
        top--;
        printf("deleted item :%d\n",item);
    }
}
void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d\n",s[i]);
    }
}
int main()
{	int n,size;
    printf("enter the size of stack:");
    scanf("%d",&size);
    while(1)
    {
        printf("1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter choice:\n");
        scanf("%d",&n);

        switch(n)
        {
        case 1:
            push(size);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
}
