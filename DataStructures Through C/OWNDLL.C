#include<stdio.h>
#include<conio.h>
struct Node
{
int item;
struct Node *next;
struct Node *prev;
};

struct Node *head=NULL,*tail=NULL;
void insert_begin(int data)
{
struct Node *newnode=(struct Node *)malloc(sizeof(struct Node*));
newnode->item=data;
newnode->prev=NULL;
if(head==NULL && tail==NULL)
{
head=newnode;
tail=newnode;
newnode->next=NULL;
}
else
{
head->prev= newnode;
newnode->next=head;
head=newnode;
}
printf("\n one node inserted!!!");
}




void insert_end(int data)
{
struct Node *newnode=(struct Node *)malloc(sizeof(struct Node *));
newnode->item=data;
newnode->next=NULL;
if(head==NULL && tail==NULL)
{
head=newnode;
tail=newnode;
newnode->prev=NULL;
}
else
{
newnode->prev=tail;
tail->next=newnode;
tail=newnode;
}

printf("\n one node inserted!!!");
}




void insert_givenpos(int data,int pos)
{
int i;
struct Node *newnode=(struct Node *)malloc(sizeof(struct Node *));
newnode->item=data;
newnode->next=NULL;
if(head==NULL && tail==NULL)
{
head=newnode;
tail=newnode;
newnode->prev=NULL;
}
else
{
struct Node *temp1=head;
struct Node *temp2;
for(i=1;i<pos;i++)
{
 temp2=temp1;
 temp1=temp1->next;
}
newnode->prev=temp1->prev;
temp1->prev=newnode;
newnode->next=temp2->next;
temp2->next=newnode;
}
printf("\none Node inserted!!!");
}

void delete_begin()
{
int de;
if(head==NULL && tail==NULL)
{
printf("\n Double Linked List is UNDERFOLOW");
}
else
{
if(head==tail)
{
head=NULL;
tail=NULL;
}
else
{
head=head->next;
}
printf("\none Node Deleted!!!");
}

}


void delete_end()
{
if(head==NULL && tail==NULL)
{
 printf("\n Double Linked List -UNDERFOLW");
}
else
{
if(head==tail)
{
head=NULL;
tail=NULL;
}
else
{
printf("%p",tail);
tail=tail->prev;
printf("%p",tail);
tail->next=NULL;
}

printf("\n one node deleted");
}

}
void delete_givenpos(int pos)
{int i;

 struct Node *temp1,*temp2;
 temp1=head;
for(i=1;i<pos;i++)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=temp1->next;
(temp1->next)->prev=temp1->prev;



}


void display()
{
if(head==NULL && tail==NULL)
{
printf("\ndll is null");
}
else
{
struct Node *temp=head;
while(temp!=NULL)
{
printf("%3d",temp->item);
temp=temp->next;
}
}
}

void revdisplay()
{
if(head==NULL && tail==NULL)
{
printf("\ndll is null");
}
else
{
struct Node *temp=tail;
while(temp!=NULL)
{
 printf("%3d",temp->item);
 temp=temp->prev;

}
}

}
void main()
{
int choice1, value, pos;
clrscr();
while(1)
{
printf("\n*********** MENU *************\n");
printf("1. Insert At Begin\n2. Insert At End \n3. Insert At Given position\n4.Delete At Begin\n5.Delete At End\n6.Delete At Given position\n7. display\n8.reversedisplay \n9.Exit\nEnter your choice: ");
scanf("%d",&choice1);
switch(choice1)
{
case 1: printf("Enter the value to be inserted: ");
scanf("%d",&value);
insert_begin(value);
break;
case 2:
 printf("Enter the value to be inserted: ");
scanf("%d",&value);
 insert_end(value);
break;
case 3:

printf("Enter the value to be inserted: ");
scanf("%d",&value);
printf("Enter the pos after which you want to insert: ");
scanf("%d",&pos);
insert_givenpos(value,pos);
break;
case 4: delete_begin();
break;
case 5: delete_end();
break;
case 6: printf("Enter the Node value to be deleted: ");
scanf("%d",&pos);
delete_givenpos(pos);
break;
case 7:display();
break;
case 8:
revdisplay();
break;
case 9:
exit(0);
default: printf("\nPlease select correct Deleting option!!!\n");


}

}
}
