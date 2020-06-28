#include<stdio.h>
#include<conio.h>
#include<alloc.h>
void insert_at_front(int);
void insert_at_end(int);
void insert_at_givenpos(int,int);
void delete_at_front();
void delete_at_end();
void delete_at_givenpos(int);
void display();
void search(int);
int length();

struct Node
{
int item;
struct Node *next;
};


struct Node *head=NULL;


void main()
{
int len,key;
int data,pos;
int ch;
clrscr();
while(1)
{
printf("\n enter your choice:");
printf("\n1.insertfront\n2.insertend\n3.insertpos\n4.deletefront\n5.deleteend\n6.deletepos\n7.display\n8.search\n9.exit");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nenter an element to be inserted:");
scanf("%d",&data);
insert_at_front(data);
break;
case 2:
printf("\nenter an element to be insert:");
scanf("%d",&data);
insert_at_end(data);
break;

case 3:
printf("\nenter an element to be insert:");
scanf("%d",&data);
L1:
printf("\nwhere u want to insert:");
scanf("%d",&pos);

len=length();

if(pos<len)
{
insert_at_givenpos(data,pos);
}
else
{
printf("\ninsertion is not possible");
printf("\nenter proper position");
goto L1;
}
break;

case 4: delete_at_front();
break;
case 5:
delete_at_end();
break;
case 6:
L2:
printf("\nwhere you want to delete:");
scanf("%d",&pos);
len=length();

if(pos<len)
{
delete_at_givenpos(pos);
}
else
{
printf("\ndeletion is not possible");
printf("\nenter proper pos");
goto L2;
}
break;

case 7:
display();
break;

case 8:
printf("\n enter search ealement:");
scanf("%d",&key);
search(key);
break;

case 9:
exit(0);
break;
}
}
}



void insert_at_front(int data)
{
struct Node *newnode=(struct Node *)malloc(sizeof(struct Node *));
newnode->item=data;
if(head==NULL)
{
newnode->next=NULL;
head=newnode;
}
else
{
newnode->next=head;
head=newnode;
}
printf("\n one node inserted successfully");
}


void insert_at_end(int data)
{
struct Node *temp;
struct Node *newnode=(struct Node *)malloc(sizeof(struct Node *));
newnode->item=data;
newnode->next=NULL;
if(head==NULL)
{
head=newnode;

}
else
{
temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;

printf("one node inserted successfully");
}
}


void insert_at_givenpos(int data,int pos)
{
int i;
struct Node *temp1, *temp2;
struct Node *newnode=(struct Node*)malloc(sizeof(struct Node*));
newnode->item=data;

newnode->next=NULL;
if(head==NULL)
{
head=newnode;

}
else
{
temp1=head;
for(i=1;i<pos-1;i++)
{
temp1=temp1->next;
}
temp2=temp1->next;
temp1->next=newnode;
newnode->next=temp2;
}
printf("\none node inserted successfully");
}
void delete_at_front()
{
struct Node *temp;
if(head==NULL)
{
printf("\n list is empty- deltion is not possible");
}
else
{
temp=head;
if(head->next==NULL)
{
head=NULL;
}
else
{
head=temp->next;
}
printf("\none node delted successfuly");
}
}
void delete_at_end()
{
struct Node *temp1,*temp2;
if(head==NULL)
{
printf("\nlist is empty- deletion is not possible");
}
else
{
temp1=head;
while(temp1->next!=NULL)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=NULL;
printf("\n one node deleted successfully");
}
}




void delete_at_givenpos(int pos)
{
int i;
struct Node *temp1,*temp2;
if(head==NULL)
{
printf("\n list is empty- deletion is not possible");
}
else
{
temp1=head;
for(i=1;i<pos;i++)
{
temp2=temp1;
temp1=temp1->next;
}
temp2->next=temp1->next;
printf("\n one node deleted successfully");
}
}
void display()
{
struct Node *temp=head;
if(head==NULL)
{
printf("empty list");
}
else
{
printf("List elements are:");
while(temp->next!=NULL)
{
printf("%3d",temp->item);
temp=temp->next;
}
printf("%3d",temp->item);

}



}
void search(int key)
{
struct Node *temp=head;
int flag=0,i=0;

while(temp!=NULL)
{
i++;
if(key==temp->item)
{
flag=1;
printf("element found at %d postition",i);
}
temp=temp->next;
}
if(flag==0)
{
printf("element not found");
}
}
int length()
{
struct Node *temp;
int count=0;
temp=head;
while(temp!=NULL)
{
count++;
temp=temp->next;
}
return count;
}



