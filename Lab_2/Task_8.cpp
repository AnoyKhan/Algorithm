#include <iostream>
using namespace std;
int main() {
    char str1[200], str2[100];
    int position;

    cout << "Enter String 1: ";
    cin >> str1;

    cout << "Enter String 2: ";
    cin >> str2;

    cout << "Enter the position to insert: ";
    cin >> position;
    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    int len2 = 0;
    while (str2[len2] != '\0') {
        len2++;
    }
    if (position < 0 || position > len1) {
        cout << "Invalid position!" << endl;
        return 0;
    }
    for (int i = len1 - 1; i >= position; i--) {
        str1[i + len2] = str1[i];
    }
    for (int i = 0; i < len2; i++) {
        str1[position + i] = str2[i];
    }
    str1[len1 + len2] = '\0';

    cout << "Result = " << str1 << endl;

    return 0;
}
