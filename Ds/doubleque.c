/*this code implements double ended queue with the operations to enqueue and dequeue in both front and rear
 *and to display the queue. */
#include<stdio.h>
#include<stdlib.h>
int q[10],r=-1,f=-1,size=10;
void enqueue_rear();
void enqueue_front();
void dequeue_rear();
void dequeue_front();
void display();

void enqueue_rear()
{	int item;
	printf("enter item:");
        scanf("%d",&item);
        if(r == (size -1))
                printf("queue overflow\n");
        else
        { 
                r++;
                q[r]= item;
                if (r==0)
                        f=0;
        }
        display();
}

void enqueue_front()
{	int item;
        if(f<=0)
                printf("cannot insert item\n");
        else
        {	printf("enter item:");
        	scanf("%d",&item);
                f--;
                q[f]= item;
                display();
        }
}


void dequeue_front()
{       if (f==-1)
                printf("queue underflow\n");
        else
        {       f++;
                if(f>r)
                        f=r=-1;
                display();
        }
}
void dequeue_rear()
{       if (r<f)
                printf("queue underflow\n");
        else
        {       if(f==r)
                        f=r=-1;
		else
			r--;
                display();
        }
}


void display()
{
        if (f==-1)
                printf("empty queue\n");
        else
        {
                printf("queue elements are displayed:\n");
                for (int i = f; i <= r; i++)
                        printf("%d\n", q[i]);
        }
}
int main()
{
        int n;
	while(1)
	{
                printf("enter ur choice:\n1.enqueue at front\n2.enqueue at rear\n3.dequeue at front\n4.dequeue st rear\n5.display\n6.exit\n");
                scanf("%d",&n);
                switch(n){

                        case  1:
                                enqueue_front();
                                break;
	                case 2:
                                enqueue_rear();
                                break;

                        case 3:
                                dequeue_front();
                                break;
	                case 4:
		                dequeue_rear();
                                break;

                        case 5:
                                display();
                                break;
	                case 6:
		                exit(0);
	                default:
		                 printf("invalid\n");
                        }
	}
        return 0;
}


