#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct Node
{
int data;
struct Node *next;
};
struct Node *head=NULL;
void create();
void front_insert(int);
void end_insert(int);
void givenpos_insert(int,int);
void front_delete();
void end_delete();
void givenpos_delete();
void search();
void display();
int length();
void main()
{
int ch,item,pos;
clrscr();
while(1)
{

printf("\n\nenter your choice from following:");
printf("\n1.create\n2.insert_front\n3.insert_end\n4.insert_givenpos\n5.delete_front\n6.delete_end\n7.delete_givenpos\n8.display\n9.search\n10.EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
create();
break;
case 2:
printf("\nenter an element to insert into list:");
scanf("%d",&item);
front_insert(item);
break;
case 3:
printf("\nenter an element to insert into list:");
scanf("%d",&item);
end_insert(item);
break;
case 4:
printf("\nenter an element to insert into list:");
scanf("%d",&item);
L1:
printf("\n enter the position\n");
scanf("%d",&pos);
if(pos>=(length())+1)
{
printf("\n ERROR:position is greater than list size");
goto L1;
}
givenpos_insert(item,pos);
break;
case 5:
front_delete();
break;
case 6:
end_delete();
break;
case 7:
givenpos_delete();
break;
case 8:
display();
break;
case 9:
search();
break;
case 10:
exit(0);
}}
}
void create()
{
//struct Node *ptr;
int size,i;
printf("\nenter list size:");
scanf("%d",&size);
for(i=1;i<=size;i++)
{
struct Node *ptr;
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
printf("eneter %d element:",i);
scanf("%d",&new_node->data);
if(head==NULL)
{
head=new_node;
new_node->next=NULL;
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=NULL;
}

}


}
void front_insert(int item)
{
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
new_node->data=item;
if(head==NULL)
{
head=new_node;
new_node->next=NULL;
}
else
{
new_node->next=head;
head=new_node;
}
printf("\n one node inserted!!!");
}
void end_insert(int item)
{
struct Node *ptr;
struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
new_node->data=item;
if(head==NULL)
{
head=new_node;
new_node->next=NULL;
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
ptr=ptr->next;
}
ptr->next=new_node;
new_node->next=NULL;
}
printf("\n one node inserted!!!");
}



void givenpos_insert(int item,int pos)
{
int i;
 struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
 struct Node *ptr,*ptr1;
 ptr=head;
 new_node->data=item;
 for(i=1;i<pos-1;i++)
 {
 ptr=ptr->next;
 }
 ptr1=ptr->next;
 ptr->next=new_node;
 new_node->next=ptr1;

 printf("\n one node inserted!!!");
}
void front_delete()
{
struct Node *ptr;
if(head==NULL)
{
printf("\nNo elements to perform delete ");
}
else
{
ptr=head;
head=ptr->next;

printf("Deleted Element is :%d",ptr->data);
}
}
void end_delete()
{
struct Node *ptr1,*ptr;
if(head==NULL)
{
printf("\n No element to perform delete");
}
else
{
ptr=head;
if(ptr->next==NULL)
{
head=NULL;
printf("\n\n Deleted Element is:%d",ptr->data);
}
else
{
while(ptr->next!=NULL)
{
ptr1=ptr;
ptr=ptr->next;
}
printf("\n Deleted Element is:%d",ptr->data);
ptr1->next=NULL;
}
}




}
void givenpos_delete()
{
}
void search()
{
int flag=0,i=0,sele;
struct Node *ptr;
ptr=head;
printf("\n enter search element:");
scanf("%d",&sele);
while(ptr!=NULL)
{
if(sele==ptr->data)
{
printf("element fount at :%d position",i+1);
flag=1;
}
ptr=ptr->next;
i++;
}

if(flag==0)
{
printf("element is not found");
}


}
void display()
{
struct Node *ptr;
if(head==NULL)
{
printf("\nNo elements in list");
}
else
{
ptr=head;
while(ptr->next!=NULL)
{
printf("%3d",ptr->data);
ptr=ptr->next;
}
    printf("%3d",ptr->data);
}
}

int length()
{
struct Node *ptr;
int l=0;
ptr=head;
while(ptr!=NULL)
{
l++;
ptr=ptr->next;
}
return l;
}
