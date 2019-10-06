#include<stdio.h>
#include<stdlib.h>
#include<process.h>
void append();
void insertatloc();
void insertatbeg();
void delatbeg();
void delatloc();
int length();
void display();
void swap_twonodes();
void reverse_data();
int len;
void insertionsort();
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node*root=NULL;;
int main()
{
		int ch;
	while(1)
	{
		printf("\n\n\n1-append\n2-insert at loc\n3-insert at beg\n4-del at beg\n5-delete at loc\n6-display\n7-swap two nodes\n8-reverse nodes\n");
		printf("\nchoice=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				
				printf("\nappend");
				append();
				break;
				
			case 2:
				printf("\ninsert at loc");
				insertatloc();
				break;
				
			case 3:
				printf("\ninsert at beg");
				insertatbeg();
				break;
				
			case 4:
				printf("\ndel at beg");
				delatbeg();
				break;
			
			case 5:
				printf("\ndelete at loc");
				delatloc();
				break;
				
			case 6:
				printf("\ndisplay");
				display();
				break;
				
			case 7:
				printf("\nswap two nodes");
				swap_twonodes();
				break;
				
			case 8:
				printf("reverse data");
				reverse_data();
				break;
				
			case 9:
				printf("insertion sort");
				insertionsort();
				break;
			default:
				printf("\ninvalid option chosen");
		}
	}
}

void append()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nenter the node data");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	
	if(root==NULL)
	{
		root=temp;
		printf("\nfirst node added");
	}
	
	else
	{
		struct node *p;
		p=root;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
		temp->prev=p;
		printf("\nnode added successfully");
	}
}

void insertatbeg()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nenter the node data");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	
	struct node *p;
	p=root;
	root=temp;
	temp->next=p;
	p->prev=temp;
	printf("\nnode added successfully");
	
}

void insertatloc()
{
	struct node *temp;
	int pos,i=1,len;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nenter the node data");
	scanf("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	
	printf("\nenter the position after whicg u wanna insert the node");
	scanf("%d",&pos);
	len=length();
	
	if(len<pos)
	{
		printf("\nnode cannot be inserted as len of list is itself %d",len);
	}
	
	else
	{
		struct node *p;
		p=root;
		while(i<pos)
		{
			p=p->next;
			i++;
		}
		temp->next=p->next;
		temp->prev=p;
		p->next->prev=temp;
		p->next=temp;
		printf("\nnode addded successfully");
	}
}

void delatbeg()
{
	struct node *p;
	p=root;
	root=p->next;
	printf("%d is getting deleted",p->data);
	p->next->prev=NULL;
	p->next=NULL;
	free(p);
	
}


void delatloc()
{	
	int pos,i=1,len;
	struct node *p,*q;
	p=root;
	len=length();
	printf("\nenter position");
	scanf("%d",&pos);
	
	if(pos>len)
	{
		printf("the length of list id %d",len);
	}
	
	else
	{
		while(i<pos-1)
		{
			p=p->next;
			i++;	
		}
		q=p->next;
		printf("\n%d is getting deleted",q->data);
		p->next=q->next;
		q->next->prev=p;
		q->next=NULL;
		q->prev=NULL;
		free(q);
	}
}

int length()
{
	struct node *p;
	int len=1;
	p=root;
	while(p->next!=NULL)
	{	
		p=p->next;
		len++;
	}
	return len;
	
}

void display()
{
	struct node *p;
	
	p=root;
	while(p!=NULL)
	{	
		printf("%d->",p->data);
		p=p->next;
		
	}
	
}

void swap_twonodes()
{
	struct node *p,*q,*r;
	int i=1,pos,len;
	printf("\n enter position");
	scanf("%d",&pos);
	p=root;
	if(pos>len)
	{
		printf("len is %d",len);
	}
	
	else
	{
	
		while(i<pos-1)
		{
			p=p->next;
			i++;
		}
		q=p->next;
		r=q->next;
		
		p->next=r;
		q->next=r->next;
		r->prev=p;
		q->prev=r;
		r->next=q;
		printf("/n SWAPPED");
	}
}


void reverse_data()
{
	struct node *p,*q;
	int len,i=1,j=1,k=1,temp;
	len=length();
	
	p=root;
	q=root;
	while(k<len)
	{
		q=q->next;
		k++;
	}
	
	while(i<(len/2))
	{
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		
		len--;
		
		p=p->next;//incrementing p
		
		q=root;//decrementing q
		while(j<len)
		{
			q=q->next;
			j++;
		}
		
		i++;
		j=1;
	}
	display();
}


void insertionsort()
{	
	struct node *p,*q,*d;
	int temp;len;
	len=length();
	for(p=root->next;p!=NULL;p=p->next)
	{
		d=p;
		while(d!=root && d->data<d->prev->data)
		{
			temp=d->data;
			d->data=d->prev->data;
			d->prev->data=temp;
			d=d->prev;
		}
	}
	
	display();
}
