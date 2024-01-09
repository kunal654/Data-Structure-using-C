#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL; 

void create();
void display();
void insertatfirst();
void insertatmiddle();
void insertatend();
int main(void)
{
    int choice;

    while (1)
    {
        printf("Press 1 to insert into the list\n");
        printf("Press 2 to display the list\n");
        printf("press 3 to insert at first \n");
        printf("press 4 to insert at middle \n");
        printf("press 5 to insert at end \n");  
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
            	insertatfirst();
            case 4:
            	insertatmiddle();
            	break; 
            case 5:
            	insertatend();
            default:
                printf("\nWrong choice\n");
        }
    }

    return 0;
}

void create()
{
    char p;
    struct node *temp, *list;
    temp = (struct node *)malloc(sizeof(struct node));
    
    if (temp == NULL)
    {
        printf("Out of Memory Space\n");
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
    struct node* list;
    list = start;

    while (list != NULL)
    {
        printf("%d =>", list->data);
        list = list->next;
    }

    printf("\n");
}
void insertatfirst()
{
	int n;
	struct node *temp;
	 temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter the value of first node that where you want your data:");
	scanf("%d",&n);
	printf("Enter the value of node that you want: ");
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
            if (list->data == n)
            {
                temp->next = list->next;
                list->next = temp;
                break;
            }
            list = list->next;
        }
        if (list == NULL)
        {
            printf("Node with value %d are not found in your list \n", n);
            free(temp);
        }
    }
}
void insertatmiddle()
{
	int l, i, node;
    printf("Enter new node value: ");
    scanf("%d", &node);

    struct node *temp, *list;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = node;
    temp->next = NULL;

    printf("Enter the location of your node where you want your new  node to be inserted: ");
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
void insertatend()
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
	
	

