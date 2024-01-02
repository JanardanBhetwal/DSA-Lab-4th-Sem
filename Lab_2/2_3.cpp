// Deque
#include <iostream>
using namespace std;
struct Deque
{
private:
    int front, rear, size, capacity;
    int *arr;

public:
    Deque(int cap)
    {
        capacity = cap;
        front = -1;
        rear = -1;
        size = 0;
        arr = new int[cap];
    }
    ~Deque()
    {
        delete arr;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push_back(int x)
    {
        if (size == capacity)
        {
            cout << "Dequeue is full.";
            return;
        }
        else
        {
            rear = (rear + 1) % capacity;
            arr[rear] = x;
            front = (front == -1) ? 0 : front;
            size++;
        }
    }

    void push_front(int x)
    {
        if (size == capacity)
        {
            cout << "Dequeue is full.";
            return;
        }

        else if (front == 0)
        {
            front = capacity - 1;
        }
        else
        {
            front--;
        }

        arr[front] = x;
        size++;
    }

    int pop_front()
    {
        int temp;
        if (isEmpty())
        {
            cout << "Dequeue is Empty";
            exit(0);
        }
        else
        {
            temp = arr[front];
            size--;
        }
        if (size == 0)
        {
            front = -1;
            rear = -1;
            return temp;
        }
        front = (front + 1) % capacity;
        return temp;
    }

    int pop_back()
    {
        int temp;
        if (isEmpty())
        {
            cout << "Deueue is Empty";
            exit(0);
        }
        else
        {
            temp = arr[rear];
            size--;
        }
        if (size == 0)
        {
            front = -1;
            rear = -1;
            return temp;
        }
        rear = (rear == 0) ? capacity - 1 : --rear;
        return temp;
    }
};

int main()
{
    struct Deque d(4);

    d.push_back(1);
    d.push_front(7);
    d.push_back(5);
    d.push_front(3);

    cout << "Insering an element to completely filled deque...\n";
    d.push_back(9);

    cout << "Removing elements...\n";
    while (!d.isEmpty())
    {
        cout << d.pop_front() << ' ' << d.pop_back() << ' ';
    }

    cout << '\n';

    return 0;
    return 0;
}
