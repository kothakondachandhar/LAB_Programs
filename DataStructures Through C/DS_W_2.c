/*
week _2:write a c program to implement the stack operations
(push,pop and display) using array
*/

#include<stdio.h>
#include<conio.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push();
void pop();
void display();
void main()
{
int item,ch,c;
clrscr();
printf("STACK PROGRAM");
while(1)
{
printf("\nselect choice from follwing");
printf("\n1.push\n2.pop \n3.display\n4.exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:push();
break;
case 2:pop();
break;
case 3: display();
break;
case 4: exit(0);
break;
default: printf("\nwrong choice");
}
}
}
void push()
{
int ele;
if(top==MAX-1)
{
printf("\nstack is overflow");
}
else
{
printf("\nenter an element to push on to stack:");
scanf("%d",&ele);
top=top+1;
stack[top]=ele;
printf("\n element inserted successfully");
}
}
void pop()
{
int ele;
if(top==-1)
{
printf("\nstack is UNDERFLOW");
}
else
{
ele=stack[top];
top--;
printf("\n deleted element from stack is:%d",ele);
printf("\nelement deleted successfully");

}
}
void display()
{
int i;
if(top==-1)
{
printf("\nno element to display- stak is empty");
return;
}
printf("\nstack elements are:\n");
for(i=0;i<=top;i++)
{
printf("%3d",stack[i]);
}
}


