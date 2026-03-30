#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *top = NULL;

int isEmpty() {
    return top == NULL;
}

void push(int item) {
    Node *newNode = new Node();
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    cout << "Pushed " << item << endl;
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Nothing to pop." << endl;
        return -1;
    } else {
        Node *temp = top;
        int item = temp->data;
        top = top->next;
        delete temp;
        cout << "Popped: " << item << endl;
        return item;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    } else {
        cout << "Top element: " << top->data << endl;
        return top->data;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements: ";
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    int choice, item;

    cout << "--- STACK IMPLEMENTATION MENU (Linked List) ---" << endl;

    do {
        cout << "\n1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n0. EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> item;
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                cout << "Exiting ..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
