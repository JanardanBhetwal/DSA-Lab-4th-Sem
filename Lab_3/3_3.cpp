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
        if (curr->next == NULL)
        {
            return head;
        }
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
    if (before == head->data)
    {
        temp->next = head;
        return temp;
    }
    while (curr->next->data != before)
    {
        curr = curr->next;
        if (curr->next == NULL)
        {
            return head;
        }
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Delete from the beginning of the linked list.

Node *delHead(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    else
    {
        Node *temp = head->next;
        delete head;
        return temp;
    }
}

// Delete from the end of the linked list

Node *delEnd(Node *head)
{
    if (head == NULL)
    {

        return NULL;
    }
    else if (head->next == NULL)
    {
        delete head->next;
        return NULL;
    }
    else
    {
        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = NULL;
        return head;
    }
}

Node *delAfter(Node *head, int after)
{
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        Node *curr = head;
        while (curr->data != after)
        {
            if (curr->next == NULL)
            {
                return head;
            }
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return head;
    }
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
    cout << endl;
}

int main()
{
    Node *head = NULL;
    head = insertBeg(head, 10);
    head = insertEnd(head, 20);
    head = insertAfter(head, 20, 40);
    head = insertBefore(head, 40, 30);
    printList(head);

    head = delHead(head);
    printList(head);

    head = delEnd(head);
    printList(head);

    head = delAfter(head, 20);
    printList(head);
    return 0;
}