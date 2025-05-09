#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coef,expo;
    struct Node *link;
};
struct Node *poly1,*poly2,*sum;
struct Node *ReadPoly()
{
    struct Node *ptr,*p,*head=NULL;
    int n;
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter coefficient and exponent\n");
    for(int i=0;i<n;i++)
    {
        ptr=malloc(sizeof(struct Node));
        printf("enter coeff%d and expo%d :",i+1,i+1);
        scanf("%d",&ptr->coef);
        scanf("%d",&ptr->expo);
        if (head==NULL)
        {
            head=ptr;
            p=head;
        }
        else
        {
            p->link=ptr;
            p=ptr;
            ptr->link=NULL;
        }
    }
    return head;
}

struct Node * Sum(struct Node *op1,struct Node *op2)
{
    struct Node *res,*p1,*p2,*ptr,*head=NULL;
    p1=op1;
    p2=op2;
    while(p1!=NULL && p2!=NULL)
    {
        res=malloc(sizeof(struct Node));
        if (p1->expo==p2->expo)
        {
            res->coef=p1->coef+p2->coef;
            res->expo=p1->expo;
            p1=p1->link;
            p2=p2->link;
        }
        else if (p1->expo>p2->expo)
        {
            res->coef=p1->coef;
            res->expo=p1->expo;
            p1=p1->link;
        }
        else
        {
            res->coef=p2->coef;
            res->expo=p2->expo;
            p2=p2->link;
        }
        if (res->coef!=0)
        {
            if (head==NULL)
            {
                head=res;
                ptr=head;
            }
            else
            {
                ptr->link=res;
                ptr=res;
            }
        }
    }
    while(p1!=NULL)
    {
        res=malloc(sizeof(struct Node));
        res->coef=p1->coef;
        res->expo=p1->expo;
        p1=p1->link;
        if (head==NULL)
        {
            head=res;
            ptr=head;
        }
        else
        {
            ptr->link=res;
            ptr=res;
        }
    }
    while(p2!=NULL)
    {
        res=malloc(sizeof(struct Node));
        res->coef=p2->coef;
        res->expo=p2->expo;
        p2=p2->link;
        if (head==NULL)
        {
            head=res;
            ptr=head;
        }
        else
        {
            ptr->link=res;
            ptr=res;
        }
    }
    return head;
}
void display(struct Node *head)
{
    if (head==NULL)
        printf("empty poly");
    
    else
    {
        struct Node *ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%dx^%d  +",ptr->coef,ptr->expo);
            ptr=ptr->link;
        }
        printf("%dx^%d\n ",ptr->coef,ptr->expo);
    }
}
int main()
{
    printf("enter details of poly1\n");
    poly1=ReadPoly();
    printf("enter details of poly2\n");
    poly2=ReadPoly();
    
    printf("poly1\n");
    display(poly1);
    printf("poly2\n");
    display(poly2);
    
    printf("sum \n");
    sum=Sum(poly1,poly2);
    display(sum);
}