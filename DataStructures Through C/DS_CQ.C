/* write a c program for circular queue*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5

int cq[max],ele,temp,rear=-1,front=-1,ch;
void insert();
void delete();
void display();
void main()
{
   clrscr();
   while(1)
   {
   printf("\n\nenter your choice from following")  ;
   printf("\n1.insertion");
   printf("\n2. deleteion");
   printf("\n3. display");
   printf("\n4.exit");
   scanf("%d",&ch);
   switch(ch)
   {
	     case 1:insert();
		     break;
	     case 2:delete();
		     break;
	     case 3:display();
		      break;
	     case 4:exit(0);
	     default:printf("invalid choice:\n");
	 }
  }
}
void insert()
{
     if((front==0)&&(rear==max-1)||(front==rear+1))
      {

	 printf("\noverflow");
	 return;
      }
      else
      {
	    printf("enter the eelements");
	    scanf("%d",&ele);
	    if(front==-1)
	    {
	      front=0;
	      rear=0;
	    }
	    else if(rear==max-1)
	    {
	      rear=0;
	      cq[rear]=ele;
	    }
	    else
	    rear=rear+1;
	    cq[rear]=ele;
	  }
    }
void display()
{
    int i;
    if(rear==-1)
     {
	   printf("\n queue is emplty");
	   return;
     }
      else if(front<=rear)
      {
	  printf("\n the queue elements are:\n");
	    for(i=front;i<=rear;i++)
	    {
	       printf("%3d",cq[i]);
	    }
      }
       else
      {
	   printf("cq elements are:");

	   for(i=front;i<=max-1;i++)




	   printf("%d\t",cq[i]);
	   for(i=0;i<=rear;i++)
	   {
	       printf("%d \t",cq[i]);
	   }
       }
}
void delete()
{

     if(front==-1)
     {
	 printf("Underflow");
	 return;
     }
     else


      ele=cq[front];
      if(front==rear)
	 {
	  front=-1;
	  rear=-1;
      }
      else if(front==max-1)
       front=0;
       else
	front++;
	printf("the deleted elements is %d",ele);
}

