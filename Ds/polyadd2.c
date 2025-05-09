/*
Write a program for addition of polynomials containing two variables using linked list. The terms of the
polynomials are ordered by the power of the first variable and then the second variable, in the descending
order. Eg: 4.x^3.y^1 + 2.x^2.y^3 + 5.x^1.y^2+7.y^2+7.y^1+5
*/

#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int coef;
    int xexpo;
    int yexpo;
    struct Node *link;
};
struct Node *poly1,*poly2,*sum;
struct Node *ReadPoly()
{
    struct Node *ptr,*p,*temp,*front,*head=NULL;
    int n;
    printf("enter number of elements:");
    scanf("%d",&n);
    printf("enter element details \n");
    for(int i=0;i<n;i++)
    {
        ptr=malloc(sizeof(struct Node));
        printf("enter coeff%d: ",i+1 );
        scanf("%d",&ptr->coef);
        printf("enter x exponent%d:",i+1);
        scanf("%d",&ptr->xexpo);
        printf("enter y exponent%d: ",i+1 );
        scanf("%d",&ptr->yexpo);
        if (head==NULL)
        {
            head=ptr;
            p=head;
        }
        else
        {
            if (ptr->xexpo<p->xexpo|| (ptr->xexpo=p->xexpo && ptr->yexpo<p->yexpo))
            {
                p->link=ptr;
                p=ptr;
                ptr->link=NULL;
            }
            else if(ptr->xexpo>p->xexpo)
            {
                temp=head;
                while (temp->xexpo>ptr->xexpo)
                {
                    front=temp;
                    temp=temp->link;
                }
                if (temp->xexpo<ptr->xexpo)
                {
                    front->link=ptr;
                    ptr->link=temp;
                }
                else
                {   
                    while (temp->yexpo>ptr->yexpo )
                    {
                        front=temp;
                        temp=temp->link;
                    }
                    if (temp->yexpo<ptr->yexpo)
                    {
                        front->link=ptr;
                        ptr->link=temp;
                    }
                    else
                    {
                        temp->coef+=ptr->coef;
                    }  
                }
            }
            else
            {
                if(ptr->yexpo==p->yexpo)
                {
                    p->coef+=ptr->coef;
                    break;
                }
                
                temp=head;
                while (temp->xexpo!=ptr->xexpo )
                {
                    front=temp;
                    temp=temp->link;
                }
                while (temp->yexpo>ptr->yexpo )
                {
                    front=temp;
                    temp=temp->link;
                }
                if (temp->yexpo<ptr->yexpo)
                {
                    front->link=ptr;
                    ptr->link=temp;
                }
                else
                {
                    temp->coef+=ptr->coef;
                }  
            }
        }
    }
    return head;
}

/*
struct Node * Sum(struct Node *op1,struct Node *op2)
{
    struct Node *res,*p1,*p2,*ptr,*head=NULL;
    p1=op1;
    p2=op2;
    while(p1!=NULL && p2!=NULL)
    {
        res=malloc(sizeof(struct Node));
        if (p1->expo==p2->expo && p1->var==p2->var)
        {
            res->coef=p1->coef+p2->coef;
            res->expo=p1->expo;
            res->var=p1->var;
            p1=p1->link;
            p2=p2->link;
        }
        else if (p1->expo>p2->expo)
        {
            res->coef=p1->coef;
            res->expo=p1->expo;
            res->var=p1->var;
            p1=p1->link;
        }
        else
        {
            res->coef=p2->coef;
            res->expo=p2->expo;
            res->var=p2->var;
            p2=p2->link;
        }
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
    while(p1!=NULL)
    {
        res=malloc(sizeof(struct Node));
        res->coef=p1->coef;
        res->expo=p1->expo;
        res->var=p1->var;
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
        res->var=p2->var;
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
*/

void display(struct Node *head)
{
    if (head==NULL)
        printf("empty poly");
    
    else
    {
        struct Node *ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%dx^%dy^%d  +",ptr->coef,ptr->xexpo,ptr->yexpo);
            ptr=ptr->link;
        }
        printf("%dx^%dy^%d  \n",ptr->coef,ptr->xexpo,ptr->yexpo);
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
    
    // printf("sum \n");
    // sum=Sum(poly1,poly2);
    // display(sum);
}