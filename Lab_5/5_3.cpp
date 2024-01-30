// Represent Queue using List
#include <iostream>
using namespace std;

#define N 100

struct Node
{
    int data, next;
};

class List
{
private:
    int avail = -1, start;
    struct Node node[N];
    int getNode() // Returns the available node
    {
        int p;
        if (avail == -1)
        {
            cout << "List is full";
            exit(0);
        }
        p = avail;
        avail = node[avail].next;
        return p;
    }

    void freeNode(int p)
    {
        node[p].next = avail;
        avail = p;
    }

    void init()
    {
        avail = 0;
        for (int i = 0; i < N - 1; i++)
        {
            node[i].next = i + 1;
        }
        node[N - 1].next = -1;
    }

public:
    List()
    {
        init();
        start = -1;
    }
    List(int first) // When creating the list
    {
        init();
        start = getNode();
        node[start].data = first;
        node[start].next = -1;
    }

    void insertBeg(int x)
    {
        int q;
        q = getNode();
        node[q].data = x;
        node[q].next = start;
        start = q;
    }

    void insertEnd(int x)
    {
        int q;
        q = getNode();
        node[q].data = x;
        int curr = start;
        while (node[curr].next != -1)
        {
            curr = node[curr].next;
        }

        node[q].next = -1;
        node[curr].next = q;
    }

    void delBeg()
    {
        int temp = start;
        start = node[start].next;
        freeNode(temp);
    }

    void delEnd()
    {
        int curr = start;
        if (curr == -1)
        {
            cout << "No element to delete";
            return;
        }
        if (node[curr].next == -1)
        {
            delBeg();
        }
        while (node[node[curr].next].next != -1)
        {
            curr = node[curr].next;
        }
    }
    int startValue()
    {
        return node[start].data;
    }
};

struct queue
{
private:
    List q;
    int top;

public:
    void enqueue(int x)
    {
        q.insertEnd(x);
    }
    int getTop()
    {
        top = q.startValue();
        return top;
    }
    int dequeue()
    {
        top = getTop();
        q.delBeg();
        return top;
    }
};

int main()
{
    struct queue q;
    q.enqueue(5);
    q.enqueue(6);
    cout << q.dequeue();
    cout << q.dequeue();
    cout << q.dequeue();
    return 0;
}