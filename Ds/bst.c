#include<stdio.h>
#include<stdlib.h>

/*Write a program to create a binary search tree (data items are integers) with the following operations
1. Insert a new node
2. Inorder traversal
3. Preorder traversal
4. Postorder traversal
5. Delete a node
6. Find the number of leaf nodes
7. Sort the input numbers
*/

struct Node 
{
    int data;
    struct Node *lchild,*rchild;
};

struct Node* Insert(struct Node* root,int data)
{
    if (root==NULL)
    {
        root=malloc (sizeof(struct Node));
        root->data=data;
        root->rchild=root->lchild=NULL;
        return root;
    }
    else if(data>root->data)
    {
        root->rchild=Insert(root->rchild,data);
    }
    else if(data<root->data)
    {
        root->lchild=Insert(root->lchild,data);
    }
    else
        printf("data already present");
    return root;
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
        printf("data not found");
        return root;
    }
    else if(data>root->data)
    {
        root->rchild=DeleteNode(root->rchild,data);
    }
    else if(data<root->data)
    {
        root->lchild=DeleteNode(root->lchild,data);
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

int countleaf(struct Node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        if (root->lchild==NULL && root->rchild==NULL)
            return 1;
        return countleaf(root->lchild)+countleaf(root->rchild);
    }
}
int main()
{
    int data,ch;
    struct Node *root= NULL;
    printf("menu\n1. Insert a new node\n2. Inorder traversal\n3. Preorder traversal\n4. Postorder traversal\n5. Delete a node\n6. Find the number of leaf nodes\n7. Sort the input numbers\n8.exit\n");
    while(ch!=8)
    {
        printf("\nenter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter data:");
                    scanf("%d",&data);
                    root=Insert(root,data);
                    break;
            case 2:Inorder(root);
                    break;
            case 3:Preorder(root);
                    break;
            case 4:Postorder(root);
                    break;
            case 5:printf("enter data:");
                    scanf("%d",&data);
                    root=DeleteNode(root,data);
                    break;
            case 6:printf("%d\n",countleaf(root));
                    break;
            case 7: Inorder(root);
                    break;
            case 8:exit(0);
        }
    }
}