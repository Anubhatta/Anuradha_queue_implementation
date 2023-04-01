#include <iostream>
using namespace std;

#define MAXSIZE 100

class Queue {
    private:
        int queue[MAXSIZE];
        int front, rear;

    public:
        Queue() {
            front = rear = -1;
        }

        bool isEmpty() {
            return (front == -1 && rear == -1);
        }

        bool isFull() {
            return (rear == MAXSIZE-1);
        }

        void enqueue(int item) {
            if (isFull()) {
                cout << "Queue is full. Cannot enqueue item." << endl;
                return;
            } else if (isEmpty()) {
                front = rear = 0;
            } else {
                rear++;
            }
            queue[rear] = item;
        }

        int dequeue() {
            if (isEmpty()) {
                cout << "Queue is empty. Cannot dequeue item." << endl;
                return -1;
            } else if (front == rear) {
                int item = queue[front];
                front = rear = -1;
                return item;
            } else {
                int item = queue[front];
                front++;
                return item;
            }
        }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(4);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}