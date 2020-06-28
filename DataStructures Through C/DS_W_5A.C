/*
write a c program on stack applications
a. evaluate postfix expression

*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>
#define MAX 100
int i=0,j=0,top=-1;
char suf[MAX],ch;
char s[MAX],op1,op2,res;
int temp,val;
float pop()
{
return(s[top--]);
}
float operate(float op1,float op2,char ch)
{
switch(ch)
{
case '+':temp=op1+op2;
break;
case '-':temp=op1-op2;
break;
case '*':temp=op1*op2;
break;
case '/':temp=op1/op2;
break;
case '^':temp=pow(op1,op2);
break;
}
return(temp);
}
void push(float val)
{
top++;
s[top]=val;
}
void main()
{
clrscr();
printf("\n Enter the suffix expression");
scanf("%s",&suf);
while(suf[i]!='\0')
{
ch=suf[i];
if(isalpha(ch))
{
printf("\n enter the value for %c",ch);
scanf("%d",&val);
push(val);
}
else
{
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
{
op2=pop();
op1=pop();
res=operate(op1,op2,ch);
push(res);
}
}
i++;
}
temp=pop();
printf("\n teh simplified answer for %s is:%d",suf,temp);
getch();
}
