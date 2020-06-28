/*
week 6: write a c program to implement scheduling algorithm
using queue
A: first in first out
*/
#include<stdio.h>
#include<conio.h>
void main()
{
char p[10][15];
int tot=0,wt[10],i,n,pt[20];
float avg=0;
clrscr();
printf("\n enter the number of tasks to be complete:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n\n\t%d process",i+1);
printf("\n enter process name:");
scanf("%s",p[i]);
printf("\n enter process time:");
scanf("%d",&pt[i]);
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=wt[i-1]+pt[i-1];
tot=tot+wt[i];
}
avg=(float)tot/n;
printf("\nTASK NAME\tTASK TIME\tWAITING TIME");
for(i=0;i<n;i++)
{
printf("\n%s\t\t%d\t\t%d",p[i],pt[i],wt[i]);
}
printf("\n Total waiting time to complete all tasks is:%d",tot);
printf("\n Average time taken to complete all tasks is:%f",avg);
getch();
}



