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
    Node *head = createLinkedList();
    Display(head);

    head = insertAtBegining(head, 71);
    head = insertAtIndex(head, 76, 3);
    head = insertAtEnd(head, 90);
    Display(head);

    return 0;
}

