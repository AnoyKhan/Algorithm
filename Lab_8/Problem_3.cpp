#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class BankQueue {
    string customers[MAX];
    int FRONT, REAR;

public:
    BankQueue() {
        FRONT = -1;
        REAR = -1;
    }

    bool isEmpty() {
        return (FRONT == -1 || FRONT > REAR);
    }

    bool isFull() {
        return (REAR == MAX - 1);
    }

    void arrival(string name) {
        if (isFull()) {
            cout << "Queue full! Please wait for some customers to be served.\n";
            return;
        }
        if (FRONT == -1)
            FRONT = 0;
        REAR++;
        customers[REAR] = name;
        cout << name << " has arrived and received token number " << REAR + 1 << ".\n";
    }

    void serve() {
        if (isEmpty()) {
            cout << "No customers waiting.\n";
            return;
        }
        cout << customers[FRONT] << " is being served now.\n";
        FRONT++;
        if (FRONT > REAR) {
            FRONT = -1;
            REAR = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No customers in queue.\n";
            return;
        }
        cout << "Current waiting line: ";
        for (int i = FRONT; i <= REAR; i++) {
            cout << customers[i];
            if (i != REAR) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    BankQueue bank;
    int choice;
    string name;

    while (true) {
        cout << "\n--- Bank Queue System ---\n";
        cout << "1. ARRIVAL (New Customer)\n";
        cout << "2. SERVE (Next Customer)\n";
        cout << "3. DISPLAY (Current Queue)\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name;
                bank.arrival(name);
                break;
            case 2:
                bank.serve();
                break;
            case 3:
                bank.display();
                break;
            case 4:
                cout << "Bank is closing. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
