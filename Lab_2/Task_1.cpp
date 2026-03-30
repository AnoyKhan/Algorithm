#include <iostream>
using namespace std;
int main() {
    char str[100];
    int n;
    cout << "string: ";
    cin >> str;
    cout << "n= ";
    cin >> n;
    int i = 0;
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    if (n <= 0 || n > length) {
        cout << "Invalid position!" << length << endl;
    } else {
        cout << "The " << n << "th character is: " << str[n - 1] << endl;
    }

    return 0;
}

