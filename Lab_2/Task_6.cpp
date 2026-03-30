#include <iostream>
using namespace std;
int main() {
    char str[100];
    int start, length;
    cout << "Enter a string: ";
    cin >> str;
    cout << "Enter the start position: ";
    cin >> start;
    cout << "Enter the length of substring: ";
    cin >> length;
    int strLength = 0;
    while (str[strLength] != '\0') {
        strLength++;
    }
    if (start <= 0 || start > strLength || start + length - 1 > strLength) {
        cout << "Invalid range!" << endl;
        return 0;
    }
    char sub[100];
    int j = 0;
    for (int i = start - 1; i < (start - 1 + length); i++) {
        sub[j++] = str[i];
    }
    sub[j] = '\0';

    cout << "Substring = " << sub << endl;

    return 0;
}
