#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node *merge(struct Node *l1, struct Node *l2)
{
    struct Node dummy;
    struct Node *tail = &dummy;

    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }

        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}

int main()
{
    struct Node *l1 = createNode(10);
    l1->next = createNode(30);
    l1->next->next = createNode(50);
    l1->next->next->next = createNode(70);

    struct Node *l2 = createNode(20);
    l2->next = createNode(25);
    l2->next->next = createNode(40);
    l2->next->next->next = createNode(80);

    printf("First linked list: ");
    display(l1);

    printf("Second linked list: ");
    display(l2);

    struct Node *result = merge(l1, l2);

    printf("Merged linked list: ");
    display(result);

    return 0;
}
