#include<stdio.h>
#include<string.h>
#define size 10
void push(char x);
void pop();
int st[size],top=-1,base=0;
int main()
{	int i,t,flag=0;
	char input[size],b;
	printf("\n enter string");
	scanf("%s",input);
	for(i=0;i<strlen(input);i++)
	{
		b=input[i];
		push(b);	
	} 
	t=strlen(input)/2;
	for(i=0;i<t;i++)
	{
		if(st[top]==st[base])
		{
			pop();
			base++;
		}
		
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("\npallindrome");
	}
	else
	{
		printf("\nnot a pallindrome");
	}
	
}

void push(char x)
{
	top++;
	st[top]=x;
}

void pop()
{
	top--;
}
