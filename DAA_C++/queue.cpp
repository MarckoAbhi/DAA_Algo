#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear) {
            rear->next = newNode; // Link the old rear to the new node
        }
        rear = newNode; // Update the rear to the new node
        if (!front) {
            front = newNode; // If the queue was empty, front is also the new node
        }
        count++;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot dequeue." << std::endl;
            return -1; // Indicate an error
        }
        Node* temp = front;
        int value = front->data; // Get the value to return
        front = front->next; // Move front to the next node
        delete temp; // Free the old front
        count--;
        if (isEmpty()) {
            rear = nullptr; // If the queue becomes empty, update rear
        }
        return value;
    }

    // Peek operation
    int peek() {
        if (isEmpty()) {
            std::cerr << "Queue is empty. Cannot peek." << std::endl;
            return -1; 
        }
        return front->data;
    }


    bool isEmpty() {
        return count == 0;
    }

    int size() {
        return count;
    }

 
    ~Queue() {
        while (!isEmpty()) {
            dequeue(); 
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element is: " << q.peek() << std::endl; 10
    std::cout << "Dequeued element is: " << q.dequeue() << std::endl;
    std::cout << "Front element is: " << q.peek() << std::endl; 

    std::cout << "Queue size is: " << q.size() << std::endl; 

    return 0;
}