// Insertion and deletion in static list

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

    void insertAfter(int after, int x) // after is the element after which insertion should be done
    {
        int q;
        q = getNode();
        node[q].data = x;
        int curr = start;

        while (node[curr].data != after)
        {
            if (curr == -1)
            {
                cout << "No such element found";
                exit(0);
            }
            curr = node[curr].next;
        }

        node[q].next = node[curr].next;
        node[curr].next = q;
    }

    // void insertBefore(int before, int x)
    // {
    //     if (before == node[start].data)
    //     {
    //         insertBeg(x);
    //     }

    //     else
    //     {
    //         int q;
    //         q = getNode();
    //         node[q].data = x;
    //         int curr = start;
    //         while (node[node[curr].next].data != before)
    //         {
    //             if (node[curr].next == -1)
    //             {
    //                 cout << "No such element found";
    //                 exit(0);
    //             }
    //             curr = node[curr].next;
    //         }
    //         node[q].next = node[curr].next;
    //         node[curr].next = q;
    //     }
    // }

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
        int temp = node[curr].next;
        freeNode(temp);
        node[curr].next = -1;
    }

    void deleteAfter(int after)
    {
        int curr = start;

        while (node[curr].data != after)
        {
            if (curr == -1)
            {
                cout << "No such element found";
                exit(0);
            }
            curr = node[curr].next;
        }
        int temp;
        temp = node[curr].next;
        if (temp == -1)
        {
            cout << "No element to delete";
            exit(0);
        }
        node[curr].next = node[temp].next;
        freeNode(temp);
    }

    void display()
    {
        int curr = start;
        while (curr != -1)
        {
            cout << node[curr].data << " ";
            curr = node[curr].next;
        }
    }
};

int main()
{
    List l1(3);

    l1.insertEnd(10);
    l1.delBeg();
    l1.display();
    return 0;
}