// This is a c program implementing the data structure linked list 
#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};

struct Node *header=NULL;
void list()
{
    header=malloc(sizeof(struct Node));
    if(!header)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    header->link=NULL;
}
void insertAtFront()
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
    temp->link=header->link;
    header->link=temp;
}

void insertAtEnd()
{   int data;
    struct Node *temp=malloc(sizeof(struct Node));
    if(!temp)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    printf("enter data:");
    scanf("%d",&data);
    struct Node *ptr=header;
    while(ptr->link!=NULL)
        ptr=ptr->link;
    temp->data=data;
    temp->link=NULL;
    ptr->link=temp;
}

void insertAtAny()
{   int data,d;
    struct Node *temp=malloc(sizeof(struct Node));
    if(!temp)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    printf("enter data after which to be inserted:");
    scanf("%d",&data);
    printf("enter data to be inserted:");
    scanf(" %d",&d);
    struct Node *ptr=header->link;
    while(ptr != NULL && ptr->data!=data)
        ptr=ptr->link;
    if (ptr==NULL)
        printf("data not found\n");
    else
    {
        temp->data=d;
        temp->link=ptr->link;
        ptr->link=temp;
    }
}

void deleteAtFront()
{   
    struct Node *ptr=header->link;
    if (ptr==NULL)
    {    
        printf("empty\n");
        return;
    }
    printf("%d removed\n",ptr->data);
    header->link=ptr->link;
    free(ptr);
}

void deleteAtEnd()
{  
    struct Node *ptr=header;
    struct Node *temp=header->link;
    if (temp==NULL)
    {    
        printf("empty\n");
        return;
    }
    while(temp->link!=NULL)
    {
        ptr=temp;
        temp=temp->link;
    
    }
    printf("%d removed\n",temp->data);
    ptr->link=NULL;
    free(temp);
}

void deleteAtAny()
{   int data;
    printf("enter data to be deleted:");
    scanf("%d",&data);
    struct Node *ptr=header->link;
    struct Node *temp=header;
    while(ptr != NULL && ptr->data!=data)
    {   temp=ptr;
        ptr=ptr->link;
    }
    if (ptr==NULL)
        printf("data not found\n");
    else
    {
        printf("%d removed\n",ptr->data);
        temp->link=ptr->link;
        free(ptr);
    }
}

void display()
{
    struct Node *ptr=header->link;
    if (ptr==NULL)
    {
        printf("empty list\n");
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
    list();
    int n;
    printf("menu\n1.insertAtFront\n2.insertAtEnd\n3.insertAtAny\n4.deleteAtFront\n5.deleteAtEnd\n6.deleteAtAny\n7.display\n8.exit\n");
    
    while(1)
    {   printf("enter choice:");
        scanf("%d",&n);
        switch(n)
        {
            case 1:insertAtFront();
                break;
            case 2:insertAtEnd();
                break;
            case 3:insertAtAny();
                break;
            case 4:deleteAtFront();
                break;
            case 5:deleteAtEnd();
                break;
            case 6:deleteAtAny();
                break;
            case 7:display();
                break;
            case 8:exit(0);
        }
    }
    return 0;
}