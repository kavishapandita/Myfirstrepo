#include<stdio.h>
#include<process.h>
void addrear(int e);
void addfront(int e);
void delfront();
void delrear();
void traverse();
#define size 10
int q[size],front=0,rear=0;
int main()
{
	int e,ch;
	printf("\n1-addrear\n2-addfront\n3-delfront\n4-delrear\n5traverse");
	while(1)
	{
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\naddrear");
				printf("\nenter the element");
				scanf("%d",&e);
				addrear(e);
				break;
			case 2:
				printf("\naddfront");
				printf("\nenter the element");
				scanf("%d",&e);
				addfront(e);
				break;
			case 3:
				printf("\ndelfront");
				delfront();
				break;
			case 4:
				printf("\ndelrear");
				delrear();
				break;
				
			case 5:
				printf("\ntraverse");
				traverse();
				break;
			case 6:
				exit(1);
			
			default:
				printf("\ninvalid option chosen");		
		}
	}
	
}
void addrear(int e)
{
	if(rear==size)
	{
		printf("\nq is full");
	}
	
	else
	{
		q[rear]=e;
		rear++;
	}
}

void addfront(int e)
{
	if(front==0)
	{
		printf("\nfront is at 0 ,thus not possible");
	}
	else
	{
		front--;
		q[front]=e;
	}
}
void delfront()
{
	int del;
	if(rear==0)
	{
		printf("\nq is empty");
	}
	else if(front==rear)
	{
		del=q[front];
		printf("%d is deleted\n");
		front=0;
		rear=0;
		printf("last element was deleted thus q resetted");
	}
	
	else
	{
		del=q[front];
		printf("%d is deleted\n");
		front++;
	}
}

void delrear()
{
	
	int del;
	if(rear==0)
	{
		printf("\nq is empty");
	}
	else if(front==rear)
	{
		del=q[rear];
		printf("%d is deleted\n");
		front=0;
		rear=0;
		printf("last element was deleted thus q resetted");
	}
	
	else
	{
		del=q[rear];
		printf("%d is deleted\n");
		rear--;
	}
}

void traverse()
{
	int i;
	for(i=front;i<rear;i++)
	{
		printf("%d->",q[i]);
	}
}
