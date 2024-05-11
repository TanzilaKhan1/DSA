#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
public:
    CircularQueue(int size) : size(size), queue(new int[size]), front(-1), rear(-1) {}
    ~CircularQueue() { delete[] queue; }

    bool isEmpty() { return front == -1 || front == (rear + 1) % size; }
    bool isFull() { return (rear + 1) % size == front; }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue overflow" << std::endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = item;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow" << std::endl;
            return -1; 
        }
        int item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return item;
    }

private:
    int size;
    int* queue;
    int front;
    int rear;
};

int main() {
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << std::endl;  
    cout << q.dequeue() << std::endl;  

    q.enqueue(40);
    q.enqueue(50);

    cout << q.dequeue() << std::endl;  
    cout << q.dequeue() << std::endl;  

    return 0;
}