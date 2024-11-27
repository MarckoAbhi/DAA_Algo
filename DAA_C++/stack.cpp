#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top; 
    int count; 

public:
    Stack() : top(nullptr), count(0) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top; 
        top = newNode; 
        count++;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
            return -1; 
        }
        Node* temp = top;
        int value = top->data; 
        top = top->next; 
        delete temp; 
        count--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot peek." << std::endl;
            return -1; 
        }
        return top->data;
    }

    bool isEmpty() {
        return count == 0;
    }

   
    int size() {
        return count;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop(); 
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top element is: " << s.peek() << std::endl; 
    std::cout << "Popped element is: " << s.pop() << std::endl; 
    std::cout << "Top element is: " << s.peek() << std::endl; 

    std::cout << "Stack size is: " << s.size() << std::endl; 

    return 0;
}