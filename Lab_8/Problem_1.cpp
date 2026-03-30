#include <iostream>
using namespace std;
#define MAX 5

class Queue {
    int arr[MAX];
    int FRONT, REAR;

public:
    Queue() {
        FRONT = -1;
        REAR = -1;
    }

    bool isEmpty() {
        return (FRONT == -1 || FRONT > REAR);
    }

    bool isFull() {
        return (REAR == MAX - 1);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << item << endl;
            return;
        }
        if (FRONT == -1)
            FRONT = 0;
        REAR++;
        arr[REAR] = item;
        cout << item << " inserted successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }
        cout << arr[FRONT] << " deleted successfully.\n";
        FRONT++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = FRONT; i <= REAR; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, item;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> item;
                q.enqueue(item);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
