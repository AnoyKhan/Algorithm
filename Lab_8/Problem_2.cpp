#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int arr[MAX];
    int FRONT, REAR;

public:
    CircularQueue() {
        FRONT = -1;
        REAR = -1;
    }

    bool isEmpty() {
        return (FRONT == -1);
    }

    bool isFull() {
        return ((REAR + 1) % MAX == FRONT);
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << item << endl;
            return;
        }
        if (FRONT == -1)      // first element insertion
            FRONT = 0;
        REAR = (REAR + 1) % MAX;
        arr[REAR] = item;
        cout << item << " inserted successfully.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to delete.\n";
            return;
        }
        int deleted = arr[FRONT];
        if (FRONT == REAR) {   // only one element was present
            FRONT = -1;
            REAR = -1;
        } else {
            FRONT = (FRONT + 1) % MAX;
        }
        cout << deleted << " deleted successfully.\n";
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int i = FRONT;
        while (true) {
            cout << arr[i] << " ";
            if (i == REAR) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, item;

    while (true) {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) return 0;

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
