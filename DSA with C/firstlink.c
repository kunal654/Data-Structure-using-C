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
    Node *p = head;
    while (p->Next != NULL)
    {
        p = p->Next;
    }
    p->Next = ptr;
    ptr->Next = NULL;
    return head;
}

Node *insertAfterNode(Node *head, Node *afterNode, int data)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->Next = afterNode->Next;
    afterNode->Next = ptr;
    return head;
}
int main()
{
    Node *head;
    Node *Node_2;
    Node *Node_3;
    Node *Node_4;

    head = (Node *)malloc(sizeof(Node));
    Node_2 = (Node *)malloc(sizeof(Node));
    Node_3 = (Node *)malloc(sizeof(Node));
    Node_4 = (Node *)malloc(sizeof(Node));

    head->data = 3;
    head->Next = Node_2;

    Node_2->data = 6;
    Node_2->Next = Node_3;

    Node_3->data = 2;
    Node_3->Next = Node_4;

    Node_4->data = 1;
    Node_4->Next = NULL;

    Display(head);

    head = insertAtBegining(head, 71);
    head = insertAtIndex(head, 76, 3);
    head = insertAtEnd(head, 90);
    head = insertAfterNode(head, Node_3, 100);
    Display(head);

    return 0;
}
