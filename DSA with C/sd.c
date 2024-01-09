#include <stdio.h>
#include <stdlib.h>

typedef struct Doubly_linklist
{
    struct Doubly_linklist *prv;
    int data;
    struct Doubly_linklist *next;
} Node;

Node *head = NULL; // Intialize the head with NULL for indicating the list is Empty;
Node *tail = NULL; // Intialize the tail with NULL for indicating the list is Empty;

void create()
{
    char p;
    do
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);
        newnode->prv = NULL;
        newnode->next = NULL;
        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->prv = tail;
            tail = newnode;
        }
        printf("Do you want to continue ? (y/n) : ");
        scanf(" %c", &p);
    } while (p == 'y' || p == 'Y');
}

void display()
{

    Node *ptr;
    ptr = head; // for Normal direction
    if (head == NULL && tail == NULL)
    {
        printf("List is Empty !");
        return;
    }
    while (ptr != NULL)
    {
        printf("<- %d ->", ptr->data);
        ptr = ptr->next;
    }
}

void insertfirst()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    newnode->prv = NULL;
    newnode->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void insertlast()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    newnode->prv = NULL;
    newnode->next = NULL;
    if (head == NULL && tail == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prv = tail;
        tail = newnode;
    }
}

void insertmiddle()
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);
    newnode->prv = NULL;
    newnode->next = NULL;
    int loc;
    printf("Enter location : ");
    scanf("%d", &loc);
    if (loc <= 0)
    {
        printf("Invalid Location !");
        return;
    }
    Node *ptr = head;
    int i = 1;
    while (i < loc - 1)
    {
        ptr = ptr->next;
        if (ptr->next == NULL)
        {
            printf("Location Exceded !");
            return;
        }
        i++;
    }
    newnode->next = ptr->next;
    ptr->next->prv = newnode;
    newnode->prv = ptr;
    ptr->next = newnode;
}

void deletefirst()
{
    Node *ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to delete !");
        return;
    }
    head = head->next;
    head->prv = NULL;
    free(ptr);
}

void deletelast()
{
    Node *ptr = tail;
    if (ptr == NULL)
    {
        printf("Nothing to delete !");
        return;
    }
    tail = tail->prv;
    tail->next = NULL;

    free(ptr);
}

void deletemiddle(){
    if(head == NULL){
        printf("Nothing to Delete !");
        return;
    }
    int loc;
    printf("Enter location : ");
    scanf("%d", &loc);
    Node *ptr = head;
    Node *q = head->next;
    int i = 1;
    while(i<loc-1){
        ptr = ptr->next;
        q = q->next;
        if(ptr->next == NULL){
            printf("Location Exceded !");
            return;
        }
        i++;
    }
    ptr->next = q->next;
    q->next->prv = ptr;
    free(q);
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n\tMenu\n");
        printf("\n1. Create\n2. Display\n3. Insert at the beginning\n4. Insert at the end\n5. Insert in the middle\n6. Delete from the beginning\n7. Delete from the end\n8. Delete from the middle\n9. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &ch);
        switch (ch)
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
            insertlast();
            break;
        case 5:
            insertmiddle();
            break;
        case 6:
            deletefirst();
            break;
        case 7:
            deletelast();
            break;
        case 8:
            deletemiddle();
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Choice !");
            break;
        }
    }
}
