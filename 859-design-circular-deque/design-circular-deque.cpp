
class Node {
public:
    int data;
    Node *next, *prev;

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

class MyCircularDeque {
    Node *front, *rear;
    int size, capacity;

public:
    MyCircularDeque(int k) {
        front = rear = NULL;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        Node *temp = new Node(value);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            temp->next = front;
            front->prev = temp;
            front = temp;
        }

        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        Node *temp = new Node(value);

        if (isEmpty()) {
            front = rear = temp;
        } else {
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }

        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        Node *temp = front;

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        Node *temp = rear;

        if (front == rear) {
            front = rear = NULL;
        } else {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return front->data;
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return rear->data;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
