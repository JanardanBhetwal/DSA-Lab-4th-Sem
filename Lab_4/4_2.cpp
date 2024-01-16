// Implement queue as Linked List

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

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

int printTop(Node *head)
{
    return head->data;
}

struct queue
{
private:
    int cap;
    int size;
    Node *head;

public:
    queue()
    {
        head = NULL;
        size = 0;
    }
    void enqueue(int x)
    {
        head = insertEnd(head, x);
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Stack is empty";
            return;
        }
        head = delHead(head);
        size--;
    }

    int totalSize()
    {
        return size;
    }

    int top()
    {
        return printTop(head);
    }
    bool isEmpty()
    {
        return head == NULL;
    }
};

int main()
{
    struct queue s;
    s.enqueue(1);
    cout << s.top() << endl;
    s.enqueue(2);
    cout << s.top() << endl;
    s.enqueue(3);
    cout << s.top() << endl;
    s.dequeue();
    cout << s.top() << endl;
    // s.dequeue();
    // cout << s.totalSize() << endl;
    // cout << s.top() << endl;
    s.dequeue();
    s.dequeue();
    cout << s.isEmpty() << endl;
    return 0;
}