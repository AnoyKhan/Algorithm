#include <iostream>
using namespace std;
int main() {
    char str1[100], str2[100];
    cout << "Enter String 1: ";
    cin >> str1;
    cout << "Enter String 2: ";
    cin >> str2;
    int len1 = 0;
    while (str1[len1] != '\0') {
        len1++;
    }
    int i = 0;
    while (str2[i] != '\0') {
        str1[len1] = str2[i];
        len1++;
        i++;
    }
    str1[len1] = '\0';
    cout << "Concatenated String: " << str1 << endl;

    return 0;
}
