// Insertion Operation

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        next = NULL;
        data = x;
    }
};

// Insert at the beginning of the linked list.

Node *insertBeg(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

// Insert at the end of the linked list.

Node *insertEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        return temp;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// Insert after the specific node of the linked list.
Node *insertAfter(Node *head, int after, int x)
{
    Node *temp = new Node(x);
    temp->data = x;
    Node *curr = head;
    while (curr->data != after)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Insert before specific node of the linked list.
Node *insertBefore(Node *head, int before, int x)
{
    Node *temp = new Node(x);
    temp->data = x;
    Node *curr = head;
    while (curr->next->data != before)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Print the linked list data

void printList(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = NULL;
    head = insertBeg(head, 10);
    head = insertBeg(head, 20);
    head = insertBeg(head, 30);
    head = insertBeg(head, 40);
    head = insertAfter(head, 30, 90);
    head = insertBefore(head, 90, 5);

    printList(head);
    return 0;
}