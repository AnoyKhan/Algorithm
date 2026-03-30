#include <iostream>
using namespace std;
const int MAX_SIZE = 15;   // TREE[1..15]

class ArrayBinaryTree {
public:
    int tree[MAX_SIZE + 1];
    int lastIndex;

    ArrayBinaryTree() {
        lastIndex = 0;
        for (int i = 1; i <= MAX_SIZE; i++)
            tree[i] = -1; // -1 = NULL
    }

    // Insert following array rules
    void insert(int value) {
        if (lastIndex == MAX_SIZE) {
            cout << "Tree is full! Cannot insert more.\n";
            return;
        }
        lastIndex++;
        tree[lastIndex] = value;
    }

    void printArray() {
        cout << "\nArray Representation (index : value)\n";
        for (int i = 1; i <= lastIndex; i++) {
            cout << i << " : " << tree[i] << "\n";
        }
        cout << endl;
    }

    void printRelations(int index) {
        if (index > lastIndex || index < 1) {
            cout << "Invalid index!\n";
            return;
        }

        cout << "\nFor index " << index << " (value = " << tree[index] << "):\n";

        // Parent
        if (index == 1)
            cout << "Parent: NULL\n";
        else
            cout << "Parent: " << tree[index / 2] << "\n";

        // Left child
        if (2 * index <= lastIndex)
            cout << "Left Child: " << tree[2 * index] << "\n";
        else
            cout << "Left Child: NULL\n";

        // Right child
        if (2 * index + 1 <= lastIndex)
            cout << "Right Child: " << tree[2 * index + 1] << "\n";
        else
            cout << "Right Child: NULL\n";
    }

    void printTree() {
        cout << "\nBinary Tree (Level Order):\n";

        int level = 1;
        while (level <= lastIndex) {
            int end = min(lastIndex, level * 2 - 1);

            for (int i = level; i <= end; i++) {
                if (tree[i] == -1) cout << "- ";
                else cout << tree[i] << " ";
            }
            cout << endl;

            level *= 2;
        }
    }
};

int main() {
    ArrayBinaryTree T;
    int n, value, index;

    // -------------------------
    // Task 1: User inserts values
    // -------------------------
    cout << "How many values do you want to insert? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        T.insert(value);
    }

    // print tree and array
    T.printArray();
    T.printTree();

    // -------------------------
    // Task 2: Parent/Child checking
    // -------------------------
    cout << "\nHow many indices do you want to check? ";
    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cout << "Enter index to check: ";
        cin >> index;
        T.printRelations(index);
    }

    // -------------------------
    // Task 3: Insert new value
    // -------------------------
    cout << "\nEnter a value to insert as next node: ";
    cin >> value;
    T.insert(value);

    cout << "\nUpdated Tree:\n";
    T.printArray();
    T.printTree();

    return 0;
}
