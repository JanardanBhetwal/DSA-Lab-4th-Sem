// Implement stack as Linked List

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

Node *insertBeg(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
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

struct _stack
{
private:
    int cap;
    int size;
    Node *head;

public:
    _stack()
    {
        head = NULL;
        size = 0;
    }
    void push(int x)
    {
        head = insertBeg(head, x);
        size++;
    }
    void pop()
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
    struct _stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top();
    s.pop();
    cout << s.top();
    s.pop();
    cout << s.totalSize();
    cout << s.top();
    s.pop();
    s.pop();
    cout << s.isEmpty();
    return 0;
}