#include <iostream>
using namespace std;
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    cout << "Length = " << length << endl;
    return 0;
}
