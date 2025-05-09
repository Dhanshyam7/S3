/*this code checks if the given string is a palindrome using doubly linked list*/
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
    char data;
    struct Node *Llink;
    struct Node *Rlink;
};

char str[50];
struct Node *header=NULL;
void list()
{
    header=malloc(sizeof(struct Node));
    if(!header)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    header->Llink=NULL;
    header->Rlink=NULL;
}
void insert(char data)
{   
    struct Node *temp=malloc(sizeof(struct Node));
    if(!temp)
    {
        printf("memory allocation failed\n");
        exit(1);
    }
    struct Node *ptr=header;
    while(ptr->Rlink!=NULL)
        ptr=ptr->Rlink;
    temp->data=data;
    temp->Rlink=NULL;
    temp->Llink=ptr;
    ptr->Rlink=temp;
}
void palindrome()
{   int i;
    struct Node *ptr=header;
    struct Node *temp=header->Rlink;
    while(ptr->Rlink!=NULL)
    {
        ptr=ptr->Rlink;
    }
    for(i=0;i<((strlen(str))/2);i++)
    {
        if (temp->data!=ptr->data)
            break;
        temp=temp->Rlink;
        ptr=ptr->Llink;
    }
    if (i==((strlen(str))/2))
        printf("palindrome");
    else
        printf("not palindrome");
}
int main()
{
    list();
    printf("enter string :");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
    {
        insert(str[i]);
    }
    palindrome();
    return 0;
}
