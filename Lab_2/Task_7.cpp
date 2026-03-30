
#include <iostream>
using namespace std;

int main() {
    char str[100];
    int start, length;

    cout << "Enter a string: ";
    cin >> str;

    cout << "Enter the start position: ";
    cin >> start;

    cout << "Enter the number of characters to delete: ";
    cin >> length;
    int strLength = 0;
    while (str[strLength] != '\0') {
        strLength++;
    }
    if (start <= 0 || start > strLength || start + length - 1 > strLength) {
        cout << "Invalid range!" << endl;
        return 0;
    }
    for (int i = start - 1; i + length <= strLength; i++) {
        str[i] = str[i + length];
    }

    cout << "Result = " << str << endl;

    return 0;
}
