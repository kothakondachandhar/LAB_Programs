#include<stdio.h>
#include<conio.h>
#define MAX 10
struct process
{
char pid[5];
int bt;
int bt1;
int wt;
};
struct process p[MAX];
int count=0,total=0;
int tq;
void getprocess(int n);
void display(int n);
void execute(int n);
void main()
{
int n;
clrscr();
printf("\n enter the number of process you want to execute:");
scanf("%d",&n);
getprocess(n);
printf("\n enter the quantum:");
scanf("%d",&tq);
execute(n);
display(n);
getch();
}
void getprocess(int n)
{
int i;
for(i=0;i<n;i++)
{
printf("\n enter process id:");
scanf("%s",&p[i].pid);
printf("\n enter the burst time:");
scanf("%d",&p[i].bt);
p[i].bt1=p[i].bt;
total=total+p[i].bt;
}
}
void execute(int n)
{
int i;
while(count < total)
{
for(i=0;i<n;i++)
{
if(p[i].bt==0)
{
continue;
}
else
{
if(p[i].bt<=tq)
{
count=count+p[i].bt;
p[i].bt=p[i].bt-tq;
count=count+tq;
printf("\n%s is the execution",p[i].pid);
}
}
}
}
}
void display(int n)
{
int i;
float awt=0;
printf("\n\n pid\tbt\twt");
printf("\n---------------------------------")    ;
for(i=0;i<n;i++)
{
printf("\n%s\t%d\t%d",p[i].pid,p[i].bt1,p[i].wt);
awt=awt+p[i].wt;
}
awt=awt*n;
printf("\n Average Waiting Time is:%f",awt);
}



