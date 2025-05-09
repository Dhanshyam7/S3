//Represent any given graph and perform depth first search and breadth first search.
#include<stdio.h>
int vertices;
void addEdge(int adjmat[vertices][vertices],int src,int dest)
{
    if (src >= vertices || dest >= vertices || src < 0 || dest < 0)
    {
        printf("Invalid vertex index.\n");
        return;
    }
    adjmat[src][dest]=1;
    adjmat[dest][src]=1;
}
void BFS(int adjmat[vertices][vertices],int visited[vertices],int start)
{
    int que[vertices],front=0,rear=0;
    que[rear++]=start;
    visited[start]=1;
    while(front<rear)
    {
        int v=que[front++];
        printf("%d\t",v);
        for (int i=0;i<vertices;i++)
        {
            if (!visited[i] && adjmat[v][i]==1)
            {
                que[rear++]=i;
                visited[i]=1;
            }
        }
    }
}

void DFS(int adjmat[vertices][vertices],int visited[vertices],int start)
{
    int stack[vertices],top=-1;
    stack[++top]=start;
    visited[start]=1;
    while(top!=-1)
    {
        int v=stack[top--];
        printf("%d\t",v);
        for (int i=0;i<vertices;i++)
        {
            if (!visited[i] && adjmat[v][i]==1)
            {
                stack[++top]=i;
                visited[i]=1;
            }
        }
    }
}

//this recursive code for DFS is also correct . u can use this too.
// void DFS(int adjmat[vertices][vertices],int visited[vertices],int start)
// {
//     int stack[vertices],top=-1;
//     stack[++top]=start;
//     visited[start]=1;
//     while(top!=-1)
//     {
//         int v=stack[top--];
//         printf("%d\t",v);
//         for (int i=0;i<vertices;i++)
//         {
//             if (!visited[i] && adjmat[v][i]==1)
//             {
//                 DFS(adjmat,visited,i);
//             }
//         }
//     }
// }

int main()
{
    int src,dest;
    printf("enter number of vertices:");
    scanf("%d",&vertices);
    int visited[vertices],adjmat[vertices][vertices],ch=0;
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
            adjmat[i][j]=0;
    }
    printf("menu\n1.add edge\n2.DFS\n3.BFS\n4.exit");
    while(ch!=4)
    {
        printf("\nenter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter source and destination vertex:");
                    scanf("%d%d",&src,&dest);
                    addEdge(adjmat,src,dest);
                    break;
            case 2:for(int i=0;i<vertices;i++)
                        visited[i]=0;
                    printf("enter start vertex:");
                    scanf(" %d",&src);
                    DFS(adjmat,visited,src);
                    break;
            case 3:for(int i=0;i<vertices;i++)
                        visited[i]=0;
                    printf("enter start vertex:");
                    scanf(" %d",&src);
                    BFS(adjmat,visited,src);
                    break;
            case 4:break;
        }
    }
}
