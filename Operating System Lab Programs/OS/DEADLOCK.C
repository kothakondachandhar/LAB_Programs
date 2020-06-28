#include<stdio.h>

main()
{
int m,n;
int c[10][10],a[10][10],ca[10][10],v[1][10],i,j,k;
int pp[8],x=0;
clrscr();
printf("enter the no f process");
scanf("%d",&m);
printf("enter the no f resources");
scanf("%d",&n);
clrscr();
printf("enter the claim matrix");
for(i=0;i<=(m-1);i++)
{
for(j=0;j<=(n-1);j++)
{
scanf("%d",&c[i][j]);
}
}
clrscr();
printf("enter the available matrix");
for(i=0;i<=(m-1);i++)
{
for(j=0;j<=(n-1);j++)
{
scanf("%d",&a[i][j]);
/*if(c[i][j]>a[i][j])  *


}}
clrscr();
for(i=0;i<=(m-1);i++)
{
for(j=0;j<=(n-1);j++)
{
ca[i][j]=c[i][j]-a[i][j];
}
}
for(i=0;i<=(m-1);i++)
{
for(j=0;j<=(n-1);j++)
{
if(ca[i][j]>=v[1][j])
x++;
else
continue;
}
if(x==(n-1))
{
for(k=0;k<(n-1);k++)
v[1][k]+=a[i][k];
pp[i]=i++;
}
}
clrscr();
printf("\n\nTHE SAFE STATE OF PROCESSESS\n\n");
for(i=0;i<m;i++)
{
printf("p%d--->",pp[i]);
}
printf("the claim matrix is\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("%3d",c[i][j]);
}
printf("\n");
}
getch();
}



