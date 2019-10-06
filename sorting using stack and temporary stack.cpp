#include<stdio.h>
#include<string.h>
#define size 10
void pushst(char x);
void pushtemp(char x);
void popst();
void poptemp();
char st[size],tempst[size];
int topst=-1,toptemp=-1;
void sort(char inp[size]);
int main()
{	
	int i;
	char inp[size];
	
	printf("enter string\n");
	scanf("%s",&inp);
	printf("%s",inp);
	sort(inp);
	
}

void sort(char inp[size])
{
	char temp;
	int i;
	printf("start");
	for(i=0;i<strlen(inp);i++)
	{
		pushst(inp[i]);
	}
	
	while(topst!=-1)
	{
		temp=st[topst];
		
		popst();
		
		while(toptemp!=-1 && tempst[toptemp]>temp)
		{
			pushst(tempst[toptemp]);
			poptemp();
		}
		pushtemp(temp);
		
		
	}
	printf("sorted");
	for(i=0;i<topst;i++)
	{
		printf("%c\n",tempst[toptemp]);
		poptemp();
	}
	
}

void pushst(char x)
{
	topst++;
	st[topst]=x;
	printf("\n %c ele pushed in st",x);
}

void pushtemp(char x)
{
	toptemp++;
	tempst[toptemp]=x;
	printf("\n %c le pushed in tempst",x);
}
void popst()
{
	topst--;
}
void poptemp()
{
	toptemp--;
}
