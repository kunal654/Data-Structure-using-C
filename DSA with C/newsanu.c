#include <stdio.h>
#include <stdlib.h>

typedef struct LinkList
{
    int data;
    struct LinkList *Next;
} Node;

void Display(Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->Next;
    }
    printf("\n");
}

Node *insertAtBegining(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->Next = head;
    head = ptr;
    return head;
}

Node *insertAtIndex(Node *head, int data, int index)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->Next;
        i++;
    }
    ptr->data = data;
    ptr->Next = p->Next;
    p->Next = ptr;
    return head;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->Next = NULL;

    if (head == NULL)
    {
        head = ptr;
        return head;
    }

    Node *p = head;
    while (p->Next != NULL)
    {
        p = p->Next;
    }
    p->Next = ptr;
    return head;
}

Node *createLinkedList()
{
    Node *head = NULL;
    int data;

    char choice;
    do
    {
        printf("Enter data for a node: ");
        scanf("%d", &data);
        head = insertAtEnd(head, data);

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice); // Use a space before %c to consume any previous newline character.

    } while (choice == 'y' || choice == 'Y');

    return head;
}

int main()
{
    Node *head = NULL;
    int choice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create a new linked list\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at a specific index\n");
        printf("4. Insert at the end\n");
        printf("5. Display the linked list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                head = createLinkedList();
                break;
            case 2:
                {
                    int data;
                    printf("Enter data to insert at the beginning: ");
                    scanf("%d", &data);
                    head = insertAtBegining(head, data);
                    break;
                }
            case 3:
                {
                    int data, index;
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    printf("Enter the index to insert at: ");
                    scanf("%d", &index);
                    head = insertAtIndex(head, data, index);
                    break;
                }
            case 4:
                {
                    int data;
                    printf("Enter data to insert at the end: ");
                    scanf("%d", &data);
                    head = insertAtEnd(head, data);
                    break;
                }
            case 5:
                Display(head);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
