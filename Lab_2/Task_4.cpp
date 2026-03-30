#include <iostream>
using namespace std;
int main() {
    char str1[100], str2[100];
    cout << "Enter String 1: ";
    cin >> str1;
    cout << "Enter String 2: ";
    cin >> str2;
    int len1 = 0, len2 = 0;
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;

    int position = -1;
    for (int i = 0; i <= len1 - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (str1[i + j] != str2[j])
                break;
        }
        if (j == len2) {
            position = i;
            break;
        }
    }

    if (position != -1)
        cout << "Position = " << position << endl;
    else
        cout << "Position = -1 (Substring not found)" << endl;

    return 0;
}
