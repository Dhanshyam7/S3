#include<stdio.h>
#include<stdlib.h>
/*
Create a binary tree with the following operations
1. Insert a new node
2. Inorder traversal
3. Preorder traversal
4. Postorder traversal
5. Delete a node
*/

struct Node 
{
    int data;
    struct Node *lchild,*rchild;
};

void BuildTree(struct Node *root, int data)
{
    char ch;
    struct Node *ptr;
    root->data=data;
    printf("if u want left node(y/n) for data %d :",root->data);
    scanf(" %c",&ch);
    if ((ch=='y') || (ch=='Y'))
    {
        ptr= malloc (sizeof(struct Node));
        printf("enter data:");
        scanf("%d",&data);
        root->lchild=ptr;
        BuildTree(ptr,data);
    }
    else
        root->lchild=NULL;
    
    printf("if u want right node(y/n) for data %d :",root->data);
    scanf(" %c",&ch);
    if ((ch=='y') || (ch=='Y'))
    {
        ptr= malloc (sizeof(struct Node));
        printf("enter data:");
        scanf("%d",&data);
        root->rchild=ptr;
        BuildTree(ptr,data);
    }
    else
         root->rchild=NULL;
}

void Inorder (struct Node *root)
{
    if (root)
    {
        Inorder(root->lchild);
        printf("%d\t",root->data);
        Inorder(root->rchild);
    }
}
void Preorder (struct Node *root)
{
    if (root)
    {
        printf("%d\t",root->data);
        Preorder(root->lchild);
        Preorder(root->rchild);
    }
}
void Postorder (struct Node *root)
{
    if (root)
    {
        Postorder(root->lchild);
        Postorder(root->rchild);
        printf("%d\t",root->data);
    }
}
struct Node* DeleteNode(struct Node *root,int data)
{
    struct Node *temp;
    if (root==NULL)
    {
        return root;
    }
    else if (root->data!=data)
    {
        root->lchild=DeleteNode(root->lchild,data);
        root->rchild=DeleteNode(root->rchild,data);
    }
    else
    {
        if (root->lchild==NULL)
        {
            temp=root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild==NULL)
        {
            temp=root->lchild;
            free(root);
            return temp;
        }
        else
        {
            temp=root->rchild;
            while(temp->lchild!=NULL)
            {
                temp=temp->lchild;
            }
            root->data=temp->data;
            root->rchild=DeleteNode(root->rchild,temp->data);
        }
    }
    return root;
}

int main()
{
    int data,ch;
    struct Node *root;
    root= malloc (sizeof(struct Node));
    printf("enter root data:");
    scanf("%d",&data);
    BuildTree(root,data);
    printf("menu\n1.Inorder traversal\n2.Preorder traversal\n3.Postorder traversal\n4.Delete a node\n5.exit\n");
    while(ch!=5)
    {
        printf("\nenter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:Inorder(root);
                    break;
            case 2:Preorder(root);
                    break;
            case 3:Postorder(root);
                    break;
            case 4:printf("enter data:");
                    scanf("%d",&data);
                    root=DeleteNode(root,data);
                    break;
            case 5:exit(0);
        }
    }
}