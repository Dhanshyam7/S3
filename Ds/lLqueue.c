/*this code implements queue using linked list*/
#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node* front=NULL;
struct Node* rear=NULL;
void enqueue()
{   int data;
    struct Node *temp=malloc(sizeof(struct Node));
    if(!temp)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    printf("enter data:");
    scanf("%d",&data);
    temp->data=data;
    temp->link=NULL;
    if(front==NULL)
    {
        rear=temp;
        front=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}

void dequeue()
{   
    if (front==NULL)
    {    
        printf("stack underflow\n");
        return;
    }
    printf("data removed: %d\n",front->data);
    struct Node *ptr=front; 
    front=front->link;
    free(ptr);
    if(front==NULL)
    {
        rear=NULL;
    }
}

void display()
{
    struct Node *ptr=front;
    if (ptr==NULL)
    {
        printf("empty queue\n");
        return;
    }
    while(ptr!=NULL)
    {  
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
}
int main()
{
    int n;
    printf("menu\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    
    while(1)
    {   printf("enter choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:enqueue();
                break;
            case 2:dequeue();
                break;
            case 3:display();
                break;
            case 4:exit(0);
            default:printf("invalid choice\n");
        }
    }
    return 0;
}