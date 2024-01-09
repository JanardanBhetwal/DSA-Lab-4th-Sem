// Deletion Operation

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

Node *insertBeg(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

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
        for (int i = 1; i < after; i++)
        {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
        return head;
    }
}

int main()
{
    Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);
    head = insertEnd(head, 50);
    printList(head);

    head = delAfter(head, 3);
    printList(head);
    return 0;
}