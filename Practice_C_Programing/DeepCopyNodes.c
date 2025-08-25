#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

struct Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));

    if (temp == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    temp->data = data;
    temp->next = NULL;

    return temp;
};

void PrintList(Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

Node *deep_copy(Node *node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        Node *new_node = newNode(node->data);
        new_node->next = deep_copy(node->next);
        return new_node;
    }
}

struct Node *create(int arr[], int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    Node *head = newNode(arr[0]);
    Node *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = newNode(arr[i]);
        current = current->next;
    }

    return head;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node *head = create(arr, size);
    struct Node *copied_head = deep_copy(head);
    PrintList(head);
    PrintList(copied_head);
    return 0;
}
