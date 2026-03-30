//Searching_and_Filtering_a_1D_Array
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int linear_search(int array[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            count++;
        }
    }
    return count;
}
int delete_element(int array[], int size, int target2) {
    int newSize = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] != target2) {
            array[newSize++] = array[i];
        }
    }
    return newSize;
}

int main() {
    srand(time(0));
    int size;
    cout << "Enter your array size: ";
    cin >> size;
    int array[size];
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100 + 1;
    }
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    int target;
    cout << "Enter your targeted element: ";
    cin >> target;
    cout << "The number " << target << " appears "
         << linear_search(array, size, target) << " times." << endl;
    cout << "Enter targeted element to delete: ";
    int target2;
    cin >> target2;
    int newSize = delete_element(array, size, target2);
    cout << "Array after deleting all occurrences of " << target2 << ": ";
    for (int i = 0; i < newSize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}