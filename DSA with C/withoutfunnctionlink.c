#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

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
                break;
            }
            case 2:
            {
                struct node *list;
                list = start;
                if (list == NULL)
                {
                    printf("List is empty\n");
                    break;
                }
                while (list != NULL)
                {
                    printf("%d ==>> ", list->data);
                    list = list->next;
                }
                printf("NULL\n");
                break;
            }
            case 3:
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
                break;
            }
            case 3

            case 9:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

