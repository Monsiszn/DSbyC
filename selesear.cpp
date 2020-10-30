#include <iostream.h>
#include <conio.h>

class sel_search
{
int d[50],s,search_val;
public:
void getdata(void);
int search(void);
void display(void);
};

void sel_search :: getdata(void)
{
cout<<endl<<endl;
cout<<"How many size of array you want to create:-";
cin>>s;
cout<<"Enter "<<s<<" Integers\n";
for(int i=0;i<s;i++)
    cin>>d[i];
cout<<"\n\nEnter your search:-";
cin>>search_val;
}

int  sel_search :: search(void)
{
for(int i=0;i<s;i++)
{
    if(d[i]==search_val)
           return(i+1);
}
return(-1);
}

void sel_search :: display(void)
{
int result;
cout<<"\n\n\n";
result=search();
if(result==-1)
    cout<<"\nEntered Search is Illegal\n";
else
    cout<<"\nSearch is Located at "<<result<<" Position";
}

void main()
{
clrscr();
sel_search o1;
o1.getdata();
o1.display();
getch();
}
