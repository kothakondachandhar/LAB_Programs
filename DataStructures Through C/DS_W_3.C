/*
week _3:write a c program to implement the queue operations
(insert,delete and display) using array
*/

#include<stdio.h>
#include<conio.h>
#define MAX 10
int q[MAX];
int rear=-1,front=0;
void insert();
void delet();
void display();
void main()
{
int ch;
clrscr();
printf("QUEUE PROGRAM");
while(1)
{
printf("\nselect choice from follwing");
printf("\n1.INSERT\n2.DELETE \n3.DISPLAY\n4.EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert();
break;
case 2:delet();
break;
case 3: display();
break;
case 4: exit(0);
default: printf("\nwrong choice");
}
}
}
void insert()
{
int ele;
if(rear==MAX-1)
{
printf("\nQueue is OVERFLOW");
}
else
{
printf("enter an element to insert into Queue:");
scanf("%d",&ele);
rear=rear+1;
q[rear]=ele;
}
 }

void delet()
{
int ele;
if(rear==-1)
{
printf("\nQueue is UNDERFLOW");
}
else
{
if(front==rear)
{
ele=q[front];
front=0;
rear=-1;
}
else
{
ele=q[front];
front++;
}
printf("\n deleted element from queue is:%d",ele);
}

}


void display()
{
int i;
if(rear==-1)
{
printf("\nQueue is EMPTY");
}
else
{
printf("\nQueue elements are:\n");
for(i=front;i<=rear;i++)
{
printf("%3d",q[i]);
}
}
}


