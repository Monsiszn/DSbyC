#include<stdio.h>
#include<conio.h>
main()
{
	int n,temp,i,j,a[20];
  	printf("Enter total numbers of elements: ");
  	scanf("%d",&n);
	printf("Enter %d elements: ",n);
  	for(i=0;i<n;i++)
      scanf("%d",&a[i]);
	for(i=n-2;i>=0;i--)
	{
      	for(j=0;j<=i;j++)
		{
           	if(a[j]>a[j+1])
			   {
			   		temp=a[j];
              		a[j]=a[j+1];
              		a[j+1]=temp;	
			   }
      	}
  	}
	printf("sorted output: ");
  	for(i=0;i<n;i++)
      printf(" %d",a[i]);
}
