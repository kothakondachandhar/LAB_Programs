#include<stdio.h>
main()
{
int a[50],b[50],i,j,m,n;
int k=-1;
int top=-1;
int pr=0;
int nn=0;
clrscr();
printf("ENTER THE NO'F PAGES U WANNA TO PROCESS\n");
scanf("%d",&m);
clrscr();
printf("ENTER THE SIZE OF MAINMEMORY(IN PAGES ONLY)\n");
scanf("%d",&nn);
clrscr();
printf("ENTER THE PAGE NUMBERS\n");
for(i=0;i<m;i++)
scanf("%d",&a[i]);
clrscr();
/*ACTUAL PROCESS BEGINS*/
printf("THE PAGES U HAVE ENTERD\n");
for(i=0;i<m;i++)
printf("%3d",a[i]);
printf("\n");
n=nn-1;
for(i=0;i<m;i++)
{
if((top!=n)&&(top<n))
{
for(j=0;j<=top;j++)
{
if(a[i]==b[j])
{
pr=1;
break;
}
else
continue;
}
if(pr==1)
{
printf("\n");
for(j=0;j<=top;j++)
{
printf("%3d",b[j]);
}
printf("\n--------------------------");
pr=0;
}
else
{
++top;
b[top]=a[i];
printf("\n");
if(top==0)
printf("%3d",b[j]);
else
{
for(j=0;j<=top;j++)
{
printf("%3d",b[j]);
}
}
printf("\n-----------------------------");
}
}
else
{
for(j=0;j<=top;j++)
{
if(a[i]==b[j])
{
pr=1;
break;
}
else
continue;
}
if(pr==1)
{
printf("\n");
for(j=0;j<=top;j++)
{
printf("%3d",b[j]);
}
printf("\n--------------------------");
pr=0;
}
else
{
if(k>=n)
k=(k%n)-1;
b[++k]=a[i];
printf("\n");
for(j=0;j<=top;j++)
{
printf("%3d",b[j]);
}
printf("\n----------------------------");
}
}
}
getch();
}




