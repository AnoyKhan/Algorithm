#include <iostream>
using namespace std;
#define SIZE 5
int stack[SIZE];
int top = -1;

int isFull() {
    return top == SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int item) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << item << endl;
    } else {
        stack[++top] = item;
        cout << "Pushed " << item << endl;
    }
}

int pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Nothing to pop." << endl;
        return -1;
    } else {
        int item = stack[top--];
        cout << "Popped: " << item << endl;
        return item;
    }
}

int peek() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
        return -1;
    } else {
        cout << "Top element: " << stack[top] << endl;
        return stack[top];
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, item;

    cout << "--- STACK IMPLEMENTATION MENU (Array) ---" << endl;

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
