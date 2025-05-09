/*this file implements the queue data structure. the operations enqueue, dequeue, and display are included*/
#include<stdio.h>
int q[10],r=-1,f=-1,size=10;
void enqueue(int item);
int dequeue();
void display();

void enqueue(int item)
{
	if(r == (size -1))
 		printf("queue overflow\n");
	else
	{ 
 		r++;
		q[r]= item;
 		if (r==0)
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
		f++;
		if(f>r)
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
 	for(int i=f;i<=r;i++)
  		printf("%d\n",q[i]);
	}
}
int main()
{
	int n,item;
	char ch='y';
	while(ch=='y')
	{
	printf("Menu:\n1.enqueue\n2.dequeue\n3.display\n");
	printf("enter your choice:");
	scanf("%d",&n);
	switch(n){
	
	case 1:
		printf("enter item:");
		scanf("%d",&item);
		enqueue(item);
		break;
	case 2:
		printf("deleted item :%d\n",dequeue());
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



