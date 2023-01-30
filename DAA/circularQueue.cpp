#include <iostream>

const int MAX_SIZE = 5;

class CircularQueue {
private:
    int a[MAX_SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }
        a[rear] = x;
        std::cout << x << " enqueued to queue" << std::endl;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int x = a[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        return x;
    }

    int getFront() {
        if (isEmpty()) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        return a[front];
    }
};

int main() {
    CircularQueue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << q.dequeue() << " dequeued from queue\n";

    std::cout << "Front item is " << q.getFront() << std::endl;

    q.enqueue(4);

    std::cout << "Queue is full: " << (q.isFull() ? "true" : "false") << std::endl;

    return 0;
}
