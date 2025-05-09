/*this code implements circular queue with its operations to enqueue , dequeue and display the queue*/
#include<stdio.h>
int q[5],r=-1,f=-1,size=3;
void enqueue(int item);
int dequeue();
void display();

void enqueue(int item)
{
        if(f == ((r+1)%size))
                printf("queue overflow\n");
        else
        { 
                r=((r+1)%size);
                q[r]= item;
                if (f==-1)
                        f=0;
        }
}
 
int dequeue()
{
        int item;
        if (f==-1)
                printf("queue underflow\n");
        else
        {
                item=q[f];
                f=((f+1)%size);
                if(f==((r+1)%size))
                        f=r=-1;
        }
        return item;
}
void display()
{
        if (f==-1)
                printf("empty queue\n");
        else 
        {
        for(int i=f;i!=r;i=((i+1)%size))
                printf("%d\n",q[i]);
        }
	printf("%d\n",q[r]);
}
int main()
{
        int n,item;
        char ch='y';
        while(ch=='y')
        {
        printf("enter ur choice:\n1.enqueue\n2.dequeue\n3.display\n");
        scanf("%d",&n);
        switch(n){

                case 1:
                        printf("enter item:");
                        scanf("%d",&item);
                        enqueue(item);
                        break;
                case 2:
                        printf("removed element:%d\n",dequeue());
                        break;
                case 3:
                        display();
                        break;
                default:break;
        }
        getchar();
        printf("do more operation(y/n):");
        scanf("%c",&ch);
        }
        return 0;
}

