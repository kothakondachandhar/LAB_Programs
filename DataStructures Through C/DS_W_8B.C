/*

week _8_b: write a c program to implemnet queue operations using Linked list

*/



#include<stdio.h>
#include<conio.h>

struct Node
{
   int item;
   struct Node *next;
};
struct Node *front = NULL;
struct Node *rear=NULL;

void enqueue(int);
void dequeue();
void display();

void main()
{
   int choice, value;
   clrscr();
   printf("\n:: QUEUE using Linked List ::\n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Inserting an Element \n2. Deqleting an Element\n3. Display Elements\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 enqueue(value);
		 break;
	 case 2: dequeue(); break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
void enqueue(int value)
{
struct Node *newnode=(struct Node *)malloc(sizeof(struct Node *));
newnode->item=value;
newnode->next=NULL;
if(front==NULL && rear==NULL)
{
       front=newnode;
       rear=newnode;
}
else
{
rear->next=newnode;
rear=newnode;
}
     printf("\nInsertion is Success!!!\n");
}


void dequeue()
{
      int de;
      if(front==NULL)
      {
      printf("\n Queue is Underflow");
      }
      else
      {
      if(front==rear)
      {
      de=front->item;
      front=rear=NULL;

      }
      else
      {
      de=front->item;
      front=front->next;
      }
      printf("deleted element is:%d",de);
       }
}
void display()
{
struct Node *temp=NULL;
if(front==NULL)
{
printf("Queue is Empty");
}
else
{
printf("\n queue elements are:");
temp=front;
while(temp!=NULL)
{
printf("%3d",temp->item);
temp=temp->next;
}
}

}
    