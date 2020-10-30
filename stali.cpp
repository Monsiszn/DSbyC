#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack
{
	int item;
	struct stack* next;
};
typedef struct stack* stptr;
int push(stptr*,int);
int pop(stptr*);
void disp(stptr);
stptr getstack(void);
int main()
{
	stptr top=NULL;
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
						{
							printf("\nEnter the item:...");
							scanf("%d",&item);
							push(&top,item);
						}
						break;
			case 2:		printf("\nThe popped item is %d",pop(&top));
						break;
			case 3:		disp(top);
						break;
			default:	printf("\nYou have entered a wrong key");
		}
		fflush(stdin);
		printf("\nDo you want to continue?...y/n...");
		scanf("%c",&ch);
		fflush(stdin);
	}while(ch=='Y'||ch=='y');
}
int push(stptr* t,int x)
{
	stptr temp;
	temp=getstack();
	temp->item=x;
	if(*t==NULL)
	{
		*t=temp;
		(*t)->next=NULL;
		return(0);
	}
	temp->next=*t;
}
int pop(stptr* t)
{
	stptr temp;
	int d;
	temp=getstack();
	if(!*t)
	{
		printf("\nEmpty stack");
		return(0);
	}
	temp=*t;
	d=temp->item;
	*t=(*t)->next;
	free(temp);
	return(d);
}
stptr getstack(void)
{
	return((stptr)malloc(sizeof(struct stack)));
}
void disp(stptr t)
{
	while(t)
	{
		if(t->next)
			printf("%d->",t->item);
		else
			printf("%d",t->item);
		t=t->next;
	}
}

