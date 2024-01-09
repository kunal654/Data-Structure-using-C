 /*NAME: MAYOUKH MODAK
ROLL: 32301220109
SEC: B
DEPT: BCA(2nd YEAR 3rd Sem)*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void create();
void display();
void insertfirst();
void insert_mid();
void insertend();
void del();
void del_last();
void del_mid();

int main()
{
    int choice;
    while (1)
    {
        printf("Press 1 to insert into the list\n");
        printf("Press 2 to display the list\n");
        printf("Press 3 to insert a node at the beginning\n");
        printf("Press 4 to insert a node at the middle\n");
        printf("Press 5 to insert a node at the end\n");
        printf("Press 6 to delete a node from the beginning\n");
        printf("Press 7 to delete a node randomly\n");
        printf("Press 8 to delete a node from the end\n");
        printf("Press 9 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
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
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

void create()
{
    struct node *temp, *list;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of Memory Space:\n");
        exit(0);
    }

    printf("Enter the data value for the node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        list = start;
        while (list->next != NULL)
        {
            list = list->next;
        }
        list->next = temp;
    }
}

void display()
{
    struct node *list;
    list = start;
    if (list == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (list != NULL)
    {
        printf("%d ==>> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

void insertfirst()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of Memory Space:\n");
        exit(0);
    }

    printf("Enter the 1st node value to insert a new node after: ");
    int m;
    scanf("%d", &m);

    printf("Enter the data value for the new node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct node *list = start;
        while (list != NULL)
        {
            if (list->data == m)
            {
                temp->next = list->next;
                list->next = temp;
                break;
            }
            list = list->next;
        }
        if (list == NULL)
        {
            printf("Node with value %d not found in the list.\n", m);
            free(temp);
        }
    }
}

void insert_mid()
{
    int l, i, node;
    printf("Enter node value: ");
    scanf("%d", &node);

    struct node *temp, *list;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of Memory Space:\n");
        exit(0);
    }

    temp->data = node;
    temp->next = NULL;

    printf("Enter  location of the node where that you want to node will be inserted: ");
    scanf("%d", &l);

    list = start;
    for (i = 1; i < l && list != NULL; i++)
    {
        list = list->next;
    }

    if (list == NULL)
    {
        printf("Node insertion failed\n");
        free(temp);
        return;
    }

    temp->next = list->next;
    list->next = temp;
    printf("Node inserted\n");
}

void insertend()
{
    struct node *temp, *list;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Out of Memory Space:\n");
        exit(0);
    }

    printf("Enter the data value for the node: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        list = start;
        while (list->next != NULL)
        {
            list = list->next;
        }
        list->next = temp;
    }
}

void del()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp;
    temp = start;
    start = start->next;
    free(temp);
    printf("Node deleted from the beginning\n");
}

void del_last()
{
    if (start == NULL){ 
        printf("List is empty\n");
        return;
    }

    struct node *temp, *prev;
    temp = start;
    prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        start = NULL;
    }
    else
    {   
        prev->next = NULL;
    }

    free(temp);
    printf("Node deleted from the end\n");
}

void del_mid()
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    int l;
    printf("Enter the location of the node after which delete operation will perform: ");
    scanf("%d", &l);

    struct node *temp, *prev;
    temp = start;
    prev = NULL;

    for (int i = 1; i < l && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Deletion can not be performed\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted\n");
}

