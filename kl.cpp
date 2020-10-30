 #include<stdio.h>
#define SIZE 3
int arr[SIZE];
int front=0;
int rear = 0;
main()
{
 int ans;
 clrscr();
 do
 {
  printf("1.Enter New Element From Right :\n");
  printf("2.Remove Element From Right :\n");
  printf("3.Enter New Element From Left :\n");
  printf("4.Remove Element From Left :\n");
  printf("5.Exit :\n");
  printf("Enter Your Choice :");
  scanf("%d",&ans);
  switch(ans)
  {
            case 1:
                        r_insert();
                        break;
            case 2:
                        r_remove();
                        break;
            case 3:
                        l_insert();
                        break;
            case 4:
                        l_remove();
                        break;
            case 5:
                        break;

            default:
                        printf("You have entered wronge choice....");
  }
 }while(ans!=5);
 getch();
 return;
}
r_insert()
{
 int newitem;
 if(rear >= SIZE)
 {
  printf("Your QUEUE is full from RIGHT side....");
  getch();
  return;
 }
 else
 {
  printf("Enter the New item :");
  scanf("%d",&newitem);
  arr[++rear]=newitem;
 }
 if(front <= 0)
 {
  front = 1;
 }
 getch();
 return;
}

r_remove()
{
 int remitem;
 if(rear <= 0)
 {
  rear = 0;
  front = 0;
  printf("Your QUEUE is EMPTY from RIGTH side...\n");
  getch();
  return;
 }
 else
 {
  remitem = arr[rear--];
  printf("The removed item is : %d\n",remitem);
 }
 getch();
 return;
}

l_remove()
{
 int remitem;
 if(front <= 0 )
 {
  printf("Your QUEUE is EMPTY from LEFT side...\n");
  getch();
  return;
 }
 else
 {
  remitem = arr[front++];
  printf("The removed item is : %d\n",remitem);
 }
 if(front > rear)
 {
  front = 0;
 }
 getch(); return;}
l_insert()
{
 int newitem;
 if(front <= 1)
 {
  front = 0;
  rear = 0;
  printf("Your QUEUE is FULL from the LEFT side...\n");
  getch();
  return;
 }
 else
 {
  printf("Enter the New element :");
  scanf("%d",&newitem);
  arr[--front]=newitem;
 }
 getch();
 return;
}
