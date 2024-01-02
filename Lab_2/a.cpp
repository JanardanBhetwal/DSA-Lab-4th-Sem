// Enqueue and Dequeue operation in Circular Queue
#include <iostream>
using namespace std;
struct Cqueue
{
private:
    int front, rear, size, capacity;
    int *arr;

public:
    Cqueue(int cap)
    {
        capacity = cap;
        front = -1;
        rear = -1;
        size = 0;
        arr = new int[cap];
    }
    ~Cqueue()
    {
        delete arr;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int x)
    {
        if (size == capacity)
        {
            cout << "Queue is full.";
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

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty";
            exit(0);
        }
        else
        {
            int temp = arr[front];
            front = (front + 1) % capacity;
            size--;
            return temp;
        }
    }
};

int main()
{
    struct Cqueue c(3);
    cout << c.isEmpty() << endl;
    c.enqueue(5);
    c.enqueue(10);
    cout << c.dequeue() << endl;
    c.enqueue(15);
    c.enqueue(20);
    cout << c.dequeue() << endl;
    cout << c.dequeue() << endl;
    cout << c.dequeue() << endl;
    return 0;
}
