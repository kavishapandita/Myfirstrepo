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
				exit(0);
			
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
		temp->link=root;
		printf("\nfirst node added");
	}
	
	else
	{
		struct node *p;
		p=root;
		while(p->link!=root)
		{
			p=p->link;
		}
		p->link=temp;
		temp->link=root;
		printf("\nelement added successfully");
	}
}

void insertatbeg()
{
	struct node *temp;
	int i=1,len;
	len=length();
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nenter data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	
	struct node *p,*q;
	p=root;
	root=temp;
	temp->link=p;
	/* OR
	temp->link=root;
	root=temp;
	*/
	printf("\nelement successfully added in the beg");
		q=root;
	while(i<len)
	{
		q=q->link;
		i++;
	}
	q->link=root;
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
	struct node *p,*q;
	int len,i=1;
	len=length();
	p=root;
	if(p->link==root)
	{
		printf("last node %d is getting deleted",p->data);
		root=NULL;
	}
	else
	{
	
	root=p->link;
	printf("\n %d will be deleted",p->data);
	p->link=NULL;
	free(p);
	printf("\nelement deleted");
	q=root;
	while(i<len)
	{
		q=q->link;
		i++;
	}
	q->link=root;
	}
	
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
	while(p->link!=root)
	{
		p=p->link;
		c++;
	}
	return c;
}

void display()
{
	struct node *p;
	int c=1,i=0;
	len=length();
	p=root;
	if(p->link==NULL)
	{
		printf("\nlist is empty");
	}
	
	else
	{
	
		while(i<len)
		{
			printf("%d->",p->data);
			p=p->link;
			i++;
			
		}
	}
	
}


