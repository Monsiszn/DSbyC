#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node * next;
};
typedef struct node* ndptr;
void append(ndptr*,int);
ndptr getnode(void);
void disp(ndptr);
int count(ndptr);
void addatbeg(ndptr*,int);
void addatpos(ndptr,int,int);
void delet(ndptr*,int);
main()
{
	ndptr root=NULL;
	int i,n,choice,data,pos;
	char ch;
	do
	{
		printf("\n...Menu:...\n...1.Create node...\n...2.Add node at beginning...\n...3.Add node at any position...\n...4.Display nodes...\n...5.Delete nodes...\n...6.Count the no of nodes...");
		printf("\n...Enter your choice:...");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	printf("\n...Enter the no of nodes to be added:...");
					scanf("%d",&n);
					for(i=1;i<=n;i++)
					{
						printf("\n...Enter info...");
						scanf("%d",&data);
						append(&root,data);
					}
					break;
			case 2:	printf("\n...Enter the data of the node which is to be added at the beginning:...");
					scanf("%d",&data);
					addatbeg(&root,data);
					break;
			case 3:	printf("\n...Enter the data and the position of the node that to be inserted respectively:...");
					scanf("%d%d",&data,&pos);
					addatpos(root,data,pos);
					break;
			case 4:	disp(root);
					break;
			case 5:	printf("\n...Enter the data of the node which is to be deleted:...");
					scanf("%d",&data);
					delet(&root,data);
					break;
			case 6:	printf("\n...The no of nodes in the list is %d",count(root));
					break;
			default:printf("\n...you've entered a wrong key'");
		};
		fflush(stdin);
		printf("\n...Do you want to continue?...Y/N...");
		scanf("%c",&ch);
		fflush(stdin);
	}while(ch=='Y'||ch=='y');
	
}
ndptr getnode(void)
{
	return((ndptr)malloc(sizeof(struct node)));
}
void append(ndptr* r,int x)
{
	ndptr temp,p;
	temp=getnode();
	temp->info=x;
	temp->next=NULL;
	p=*r;
	if(!*r)
		*r=temp;
	else
	{
		while(p->next)
			p=p->next;
		p->next=temp;
	}
}
void addatbeg(ndptr* r,int x)
{
	ndptr temp;
	temp=getnode();
	temp->info=x;
	temp->next=*r;
	*r=temp;
}
void addatpos(ndptr r,int data,int pos)
{
	ndptr temp;
	int i;
	temp=getnode();
	temp->info=data;
	for(i=1;i<pos-1;i++)
		r=r->next;
	temp->next=r->next;
	r->next=temp;
}
void delet(ndptr* r,int x)
{
	ndptr prev,temp;
	temp=*r;
	while(temp)
	{
		if(temp->info==x)
		{
			if(temp==*r)
				*r=(*r)->next;
			else
				prev->next=temp->next;
			free(temp);
			return;
		}
		else
		{
			prev=temp;
			temp=temp->next;
		}
	}
	printf("\n...Data not found in the list..");
}
void disp(ndptr r)
{
	while(r)
	{
		if(r->next)
			printf("%d->",r->info);
		else
			printf("%d",r->info);
		r=r->next;
	}
}
int count(ndptr r)
{
	int c=0;
	while(r)
	{
		c++;
		r=r->next;
	}
	return(c);
}
