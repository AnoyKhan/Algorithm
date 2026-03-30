#include <iostream>
using namespace std;
int main() {
    char str[100];
    int n;
    char newChar;
    cout << "string: ";
    cin >> str;
    cout << "n= ";
    cin >> n;
    cout << "character: ";
    cin >> newChar;
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    if (n <= 0 || n > length) {
        cout << "Invalid position! " << length << endl;
    } else {
        str[n - 1] = newChar;
        cout << "Updated string: " << str << endl;
    }
    return 0;
}
