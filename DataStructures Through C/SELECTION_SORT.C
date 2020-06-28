#include<stdio.h>
#include<conio.h>
void main()
{
int a[10],i,n,j,temp;
clrscr();
printf("\n enter array size");
scanf("%d",&n);
printf("\n enter array elements");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\n array before sorting");
for(i=0;i<n;i++)
printf("%3d",a[i]);
printf("\n selection sort");
for(i=0;i<=n-1;i++)
{
for(j=i+1;j<=n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\narray after sorting");
for(i=0;i<n;i++)
printf("%3d",a[i]);
getch();
}
