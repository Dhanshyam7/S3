/*this code implements stack using linked list*/
#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *link;
};
struct Node* top=NULL;
void list()
{
    top=malloc(sizeof(struct Node));
    if(!top)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    top->link=NULL;
}
void push()
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
    temp->link=top->link;
    top->link=temp;
}

void pop()
{   
    struct Node *ptr=top->link;
    if (ptr==NULL)
    {    
        printf("stack underflow\n");
        return;
    }
    top->link=ptr->link;
    printf("data removed: %d\n",ptr->data);
    free(ptr);
}

void display()
{
    struct Node *ptr=top->link;
    if (ptr==NULL)
    {
        printf("empty stack\n");
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
    printf("menu\n1.push\n2.pop\n3.display\n4.exit\n");

    while (1)
    {
        printf("enter choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1: push();
            break;
        case 2: pop();
            break;
        case 3: display();
            break;
        case 4: exit(0);
        default: break;
        }
    }
    return 0;
}
