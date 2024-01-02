// Enque and Deque operation in Linear queue
#include <iostream>
using namespace std;
struct queue
{
private:
    int front, rear, size, capacity;
    int *arr;

public:
    queue(int cap)
    {
        capacity = cap;
        front = rear = -1;
        size = 0;
        arr = new int[cap];
    }
    ~queue()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return ((rear == -1) || front == rear + 1);
    }
    bool isFull()
    {
        return (rear == capacity - 1);
    }
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue is Full";
            return;
        }
        else if (rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            exit(0);
        }
        else
        {
            int temp = arr[front];
            front++;
            return temp;
        }
    }
};
int main()
{
    struct queue q(3);
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.isEmpty() << endl;
    cout << q.isFull() << endl;
    cout << q.dequeue() << endl;

    return 0;
}