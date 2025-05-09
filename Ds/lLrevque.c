/*this code reverses the given queue using stack */
#include <stdio.h>
#include<stdlib.h>
void display();
struct Node
{
    int data;
    struct Node *link;
};
struct Node* front=NULL;
struct Node* rear=NULL;
struct Node* top=NULL;
void enqueue(int data)
{
    struct Node *temp=malloc(sizeof(struct Node));
    if(!temp)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    temp->data=data;
    temp->link=NULL;
    if(rear==NULL)
    {
        rear=front=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}

int dequeue()
{
    if(front==NULL)
    {
        return -1;
    }
    struct Node *ptr=front;
    front=front->link;
    int data=ptr->data;
    free(ptr);
    if (front==NULL)
        rear=NULL;
    return data;
}

void push(int data)
{   
    struct Node *temp=malloc(sizeof(struct Node));
    if(!temp)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    temp->data=data;
    if (top==NULL)
    {
        top=temp;
        top->link=NULL;
    }
    else
    {
        temp->link=top;
        top=temp;
    }
}

int pop()
{   
    struct Node *ptr=top;
    if (ptr==NULL)
    {
        return -1;
    }
    top=ptr->link;
    int data=ptr->data;
    free(ptr);
    return data;
}

void querev()
{   int c;
    while((c=dequeue())!=-1)
    {
        push(c);
    }
    while ((c=pop())!=-1)
    {
        enqueue(c);
    }
    display();
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
    int n,data;
    printf("menu\n1.enqueue\n2.dequeue\n3.queue reversal\n4.display\n5..exit\n");
    
    while(1)
    {   printf("enter choice");
        scanf("%d",&n);
        switch(n)
        {
            case 1:printf("enter data");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:data=dequeue();
                if(data==-1)
                {
                    printf("queue is empty\n");
                    break;
                }
                printf("data removed: %d\n",data);
                break;
            case 3:querev();
                break;
            case 4:display();
                break;
            case 5:exit(0);
            default:printf("invalid\n");
        }
    }
    return 0;
}