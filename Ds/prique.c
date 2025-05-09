/*this is the code to implement priority queue. Operations enqueue, dequeue, and display are included.
 *Operations are done with respect to the priority levels*/
#include<stdio.h>
#include<stdlib.h>
# define size 5
#define max_p 3 
int q[max_p][size],f[size],r[size];
void enqueue(int p);
void dequeue();
void display();

void enqueue(int p)
{	int item;
        if(r[p] == (size -1))
                printf("full\n");
        else
        { 	printf("enter item:");
                scanf("%d",&item);
                r[p]++;
                q[p][r[p]]= item;
                if (r[p]==0)
                        f[p]=0;
        }
}

void dequeue()
{
	int item,p=0;
	while(p<max_p)
	{
        	if (f[p]==-1)
                	p++;
        	else
        	{
                	item=q[p][f[p]];
                	f[p]++;
                	if(f[p]>r[p])
                        	f[p]=r[p]=-1;
			break;
        	}
	}
	if (p==max_p)
		printf("queue underflow");
	else
		printf("deleted item :%d\n",item);
}
void display()
{
	int i,flag=1;
	for(i=0;i<max_p;i++)
	{
		if (f[i]!=-1)
			{
			flag=0;
			break;
			}
	}
	if (flag==1)
	{
		printf("EMPTY");
	}
	else
	{
		int p=0;
		while(p<max_p)
		{
			if (f[p]==-1)
			{
                		p++;
				printf("\n");
			}
        	else
        	{
        		for(i=f[p];i<=r[p];i++)
                		printf("%d\t",q[p][i]);
			p++;
			printf("\n");
			}

 		}
	}
}
int main()
{
	int n,p;
	for(int i=0;i<size;i++)
	{
        	f[i]=r[i]=-1;
	}

    while(1)
    {
	    printf("enter ur choice:\n1.enqueue\n2.dequeue\n3.display\n4.Exit\n");
	    scanf("%d",&n);
	    switch(n)
	    {
	    case 1:
	    	printf("enter priority level(1-3):");
	    	scanf("%d",&p);
	    	enqueue((p-1));
	    	break;
	    case 2:
	    	dequeue();
	    	break;
	    case 3:
	    	display();
	    	break;
	    case 4:
	    	exit(0);
	    default:break;
	    }
    }
	return 0;
}

