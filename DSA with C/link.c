/*NAME: KUNAL GAUTAM
ROLL: 32301222091
SEC: B
DEPT: BCA(2nd YEAR 3rd Sem)*/
// WAP TO CREATE AND IMPLEMENT A LINKED LIST
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
#define NULL0
struct node
{
int data;
struct node *next;
};
void create ();
void display();
void insertfirst();
void insert_mid();
void insertend();
void del();
void del_last();
void del_mid();
struct node *start=NULL;

void main()
{

int choice;
while(1)
{
printf("press 1 to insert to list \n");
printf("press 2 to display list \n");
printf("press 3 to insert node at first \n");
printf("press 4 to insert node at middle \n");
printf("press 5 to insert node at end \n");
printf("press 6 to delete node from first \n");
printf("press 7 to delete node randomly \n");
printf("press 8 to delete node from end \n");
printf("press 9 to exit \n");
printf("enter your choice:  \n");
scanf("%d",&choice);
switch(choice)
{
case 1:
create();
break;
case 2:
display();
break;

case 3:
insertfirst();
break;
case 4:
insert_mid();
break;

case 5:
insertend();
break;
case 6:
del();
break;
case 7:
del_mid();
break;
case 8:
del_last();
break;
case 9:

exit(1);
default:
printf("wrong choice");
}

}

}

void create()
{ char p ;

        struct node *temp,*list;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("out of Memory Space:/n");
                exit(0);
        }

        printf("Enter the data value for the node:");
        scanf("%d",&temp->data);
        temp->next=NULL;
        scanf("%c",&p);

       
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                list=start;
                while(list->next!=NULL)
                {
                        list=list->next;
                }
                list->next=temp;
        }
}
void display()
{
struct node *list;
list=start;
while(list != NULL)
{

printf("%d ==>>",list-> data);
list=list-> next;
}
}
void insertfirst()
{
struct node *temp,*list;
  int p=0 ;
  int m;
  printf("enter the 1st node value to insert new node: ");
        scanf("%d",&m);
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("out of Memory Space:\n");
                exit(0);
        }

        printf("Enter the data value for the node:");
        scanf("%d",&temp->data);
        temp->next=NULL;
        scanf("%c",&p);

       
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                list=start;
                while(list->next!=NULL)
                {
                    if(list->data==m)
                    {
                    p=1;
                    break;
}
list->next=temp;
                }
                if(p==1)
                {
                temp->next=list->next;
                list->next=temp;
}
               
        }
}
void insert_mid()
{
int l,i,node;
struct node *list,*temp;
temp=(struct node *)malloc(sizeof(struct node));
if (temp==NULL)
{
printf("you are out of memory\n");
}
else
{

printf("enter node value: ");
scanf("%d",&node);
temp->data=node;
printf("enter location of the node where the node will be inserted: \n");
scanf("%d",&l);
list=start;
for(i=0;i<l;i++)
{
list=list->next;
if(list==NULL)
{
printf("node insertion failed\n");
}
}
temp->next=list->next;
list->next=temp;
printf("node inserted\n");
}
}

void insertend() {
  char p ;

        struct node *temp,*list;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("out of Memory Space:/n");
                exit(0);
        }

        printf("Enter the data value for the node:");
        scanf("%d",&temp->data);
        temp->next=NULL;
        scanf("%c",&p);

       
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                list=start;
                while(list->next!=NULL)
                {
                        list=list->next;
                }
                list->next=temp;
        }

}
void del()  
{  
    struct node *ptr1;  
    if(start == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else  
    {  
        ptr1 = start;  
        start = ptr1->next;  
        free(ptr1);  
        printf("\nNode deleted from the begining ...\n");  
    }  
}  
void del_last()
{
struct node *temp, *ptr0;
if(start==NULL)
{
printf("\n List is empty");
}
else if(start->next==NULL)
{
start=NULL;
free(start);
printf("only node deleted");
}
else
{
temp=start;
while(temp->next!=NULL)
{
ptr0=temp;
temp=temp->next;
}
ptr0->next=NULL;
free(temp);
printf("node deleted");
}
}
void del_mid()
{
struct node *ptr,*ptr0;
int l,i;
printf("enter the location of the node after which delete operation will perform: ");
scanf("%d",&l);
ptr=start;
for(i=0;i<l;i++)
{
ptr0=ptr;
ptr=ptr->next;
if(ptr==NULL)
{
printf("\n deletion can not be performed");

}
}
ptr0->next=ptr->next;
free(ptr);
printf("\n node deleted");
}
