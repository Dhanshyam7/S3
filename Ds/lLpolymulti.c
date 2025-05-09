//polynomial multiplication using linked
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coef,expo;
    struct Node *link;
};
struct Node *poly1,*poly2,*pro;

 
void sort(struct Node *head,int k)
{
    struct  Node *ptr;
    for (int i = 1; i < k; i++)
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            if (ptr->expo<ptr->link->expo)
            {
                int temp=ptr->coef;
                ptr->coef=ptr->link->coef;
                ptr->link->coef=temp;
                temp=ptr->expo;
                ptr->expo=ptr->link->expo;
                ptr->link->expo=temp;
            }
            ptr=ptr->link;
        }
    }
    
}
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
    sort(head,n);
    return head;
}

struct Node * Product(struct Node *op1,struct Node *op2)
{
    struct Node *res,*p1,*p2,*ptr,*head=NULL,*temp;
    p1=op1;
    int k=0;
    while(p1!=NULL)
    {   p2=op2;
        while(p2!=NULL)
        {
            res=malloc(sizeof(struct Node));
            res->coef=p1->coef*p2->coef;
            res->expo=p1->expo+p2->expo;
            if (head==NULL)
            {
                head=res;
                ptr=head;
                k++;
            }
            else
            {
                temp=head;
                while(temp!=NULL)
                {
                    if (temp->expo==res->expo)
                    {
                        temp->coef+=res->coef;
                        break;
                    }
                    temp=temp->link;
                }
                if (temp==NULL)
                {
                    ptr->link=res;
                    ptr=res;
                    k++;
                }
            }
            p2=p2->link;
        }
        p1=p1->link;
    }
    sort(head,k);
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
    
    printf("product \n");
    pro=Product(poly1,poly2);
    display(pro);
}