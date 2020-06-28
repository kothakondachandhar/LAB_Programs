/*week 1: write a c program to implement a list using array with insert,
delete, display,sort operations*/


#include<stdio.h>
#include<conio.h>
#define MAX 10
void create();
void insert();
void display();
void search();
void delet();
void sort();

int a[MAX],i,n,pos,newi;
void main()
{
int ch;
clrscr();
while(1)
{
printf("\n select your choice from following");
printf("\n1.create\n2.insert\n3.delete\n4.display\n5.search\n6.sort\n7.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:create();
break;
case 2:insert();
break;
case 3:delet();
break;
case 4:display();
break;
case 5:search();
break;
case 6:sort();
break;
case 7:exit(0);
default:printf("\nenter your correct choice:");
}
}
}
void create()
{
printf("\nenter the size of list(size<=10):");
scanf("%d",&n);
printf("\nenter elements into list:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
}

void insert()
{
printf("\nenter an element to insert:");
scanf("%d",&newi);
printf("\n enter the position to insert:");
scanf("%d",&pos);
for(i=n;i>=pos-1;i--)
{
a[i]=a[i-1];
}
a[pos-1]=newi;
n++;
}

void display()
{
printf("\n list of elements are:");
for(i=0;i<n;i++)
{
printf("%2d",a[i]);
}
}

void delet()
{
printf("\nenter the position to delete:");
scanf("%d",&pos);
printf("\n Deleted Element is:%d",a[pos-1]);
for(i=pos-1;i<n;i++)
{
a[i]=a[i+1];
}
n--;
}

void search()
{
int se,flag=0;
printf("\n enter search element:");
scanf("%d",&se);
for(i=0;i<n;i++)
{
if(se==a[i])
{
printf("\n element found at:%d",i+1);
flag=1;
}
}
if(flag==0)
{
printf("\n element not found");
}
}

void sort()
{
int j,temp;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i]<a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\n after sorting array elements are:");
for(i=0;i<n;i++)
{
printf("%2d",a[i]);
}
}



