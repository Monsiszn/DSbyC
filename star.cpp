#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 20
int push();
int pop();
void disp();
int stack[max];
int top=-1;
int main()
{
	int item,choice,n,i;
	char ch;
	do
	{
		printf("\nMenu:...\n...1.Push...\n...2.Pop...\n...3.Display...\nEnter your choice:...");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :	printf("\nEnter the no of elements to be pushed:...");
						scanf("%d",&n);
						for(i=1;i<=n;i++)
							push();
						break;
			case 2:		printf("\nThe popped item is %d",pop());
						break;
			case 3:		disp();
						break;
			default:	printf("\nYou have entered a wrong key");
		}
		fflush(stdin);
		printf("\nDo you want to continue?...y/n...");
		scanf("%c",&ch);
		fflush(stdin);
	}while(ch=='Y'||ch=='y');
}
int push()
{
	int item;
	if(top==max-1)
	{
		printf("\nStack is full");
		return(0);
	}
	printf("\n...Enter the item:...");
	scanf("%d",&item);
	top++;
	stack[top]=item;
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("\nStack is empty");
		return(0);
	}
	item=stack[top];
	top--;
	return(item);
}
void disp()
{
	if(top==-1)
	{
		printf("\nStack is empty");
		exit(0);
	}
	for(int i=top;i>=0;i--)
		printf("%d\n",stack[i]);
}
