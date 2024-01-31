// Insertion and deletion in Doubly Linked List

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class DLL
{
private:
    Node *head;

public:
    DLL()
    {
        head = NULL;
    }
    void insertBeg(int x)
    {
        Node *temp = new Node(x);
        if (head == NULL)
        {
            head = temp;
            return;
        }
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insertEnd(int x)
    {
        Node *temp = new Node(x);
        Node *curr = head;
        if (head == NULL)
        {
            head = temp;
            return;
        }
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }

    void insertAfter(int after, int x)
    {
        Node *temp = new Node(x);
        Node *curr = head;
        while (curr->data != after)
        {
            curr = curr->next;
            if (curr == NULL)
            {
                cout << "No such element"<<endl;
                return;
            }
        }
        temp->next = curr->next;
        if (temp->next != NULL)
        {
            temp->next->prev = temp;
        }
        temp->prev = curr;
        curr->next = temp;
    }

    void deleteBeg()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd()
    {
        Node *curr = head;
        if (head == NULL || head->next == NULL)
        {
            delete curr;
            head = NULL;
        }
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        Node *temp = curr;
        curr = curr->prev;
        curr->next = NULL;
        delete temp;
    }

    void deleteAfter(int after)
    {
        Node *temp;
        Node *curr = head;
        while (curr->data != after)
        {
            curr = curr->next;
            if (curr->next == NULL)
            {
                cout << "No such element"<<endl;
                return;
            }
        }
        temp = curr->next;
        curr->next = curr->next->next;
        curr->next->prev = curr;
        delete temp;
    }

    void display()
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    DLL l1;
    l1.insertBeg(5);
    l1.insertBeg(4);
    l1.insertBeg(3);
    l1.insertEnd(6);
    l1.insertAfter(4, 8);
    l1.display();
    l1.deleteAfter(6);
    l1.display();
    l1.deleteEnd();
    l1.display();

    return 0;
}