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
int len;
void swap_twonodes();
void reverse_data();
void bubblesort();
void selectionsort();
struct node
{
	int data;
	struct node *link;
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
				printf("\n swap two nodes");
				swap_twonodes();
				break;
				
			case 8:
				printf("\n reverse data elements of the list");
				reverse_data();
				break;
				
			case 9:
				printf("\n bubble sort");
				bubblesort();
				break;
			
			case 10:
				printf("\n selection sort");
				selectionsort();
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
	printf("\nenter data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	if(root==NULL)
	{
		root=temp;
		printf("\nfirst node added");
	}
	
	else
	{
		struct node *p;
		p=root;
		while(p->link!=NULL)
		{
			p=p->link;
		}
		p->link=temp;
		printf("\nelement added successfully");
	}
}

void insertatbeg()
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nenter data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	struct node *p;
	p=root;
	root=temp;
	temp->link=p;
	/* OR
	temp->link=root;
	root=temp;
	*/
	printf("\nelement successfully added in the beg");
	
}

void insertatloc()
{
	struct node *temp;
	int pos,i=1;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nenter data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	len=length();
	printf("\nenter the position after which element needs to be inserted ");
	scanf("%d",&pos);
	
	if(pos>len)
	{
		printf("\ncannot add as len is %d",len);
	}
	
	else
	{
		struct node *p;
		p=root;
		while(i<pos)
		{
			p=p->link;
			i++;
		}
		temp->link=p->link;
		p->link=temp;
		printf("\nelement added at position %d",pos);
	}
}

void delatbeg()
{
	struct node *p;
	p=root;
	root=p->link;
	printf("\n %d will be deleted",p->data);
	p->link=NULL;
	free(p);
	printf("\nelement deleted");
}

void delatloc()
{
	int pos,i=1;
	struct node *p,*q;
	p=root;
	printf("\nenter position");
	scanf("%d",&pos);
	len=length();
	
	if(pos>len)
	{
		printf("\ncannot del as length of list is %d",len);
	}
	
	else
	{
		while(i!=pos-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		printf("\n%d is getting deleted",q->data);
		p->link=q->link;
		q->link=NULL;
		free(q);		
	}	
}


int length()
{
	struct node *p;
	int c=1;
	p=root;
	while(p->link!=NULL)
	{
		p=p->link;
		c++;
	}
	return c;
}

void display()
{
	struct node *p;
	int c=1;
	p=root;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->link;
		
	}
	
	
}

void swap_twonodes()
{
	struct node *p,*q,*r;
	int pos,i=1;
	p=root;
	printf("\nenter position");
	scanf("%d",&pos);	
	if(root==NULL)
	{
		printf("\nlink list is empty");
	}
	
	else if(p->link==NULL)
	{
		printf("\ntwo nodes required only one present");
	}
	
	else
	{
		while(i<pos-1)
		{
			p=p->link;
			i++;
		}
		q=p->link;
		r=q->link;
		
		p->link=q->link;
		q->link=r->link;
		r->link=q;
		
		printf("\nswapped yo!");
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
		q=q->link;
		k++;
	}
	
	while(i<(len/2))
	{
		temp=p->data;
		p->data=q->data;
		q->data=temp;
		
		len--;
		
		p=p->link;//incrementing p
		
		q=root;//decrementing q
		while(j<len)
		{
			q=q->link;
			j++;
		}
		
		i++;
		j=1;
	}
	display();
}

void bubblesort()
{
	int i,j,temp;
	struct node *p;
	p=root;
	len=length();
	
	for(i=0;i<len;i++)
	{	
	 	p=root;
		while(p->link!=NULL)
		{
			if(p->data>p->link->data)
			{
				temp=p->data;
				p->data=p->link->data;
				p->link->data=temp;
				
			}
			p=p->link;
		}
	}
	display();
}

void selectionsort()
{
	struct node *p,*q,*min;
	int temp;
	
	p=root;
	for(p=root;p!=NULL;p=p->link)
	{
		min=p;
		for(q=p->link;q!=NULL;q=q->link)
		{
			if(min->data>q->data)
			{
				min=q;
			}
		}
		temp=p->data;
		p->data=min->data;
		min->data=temp;
	}
	display();
}

