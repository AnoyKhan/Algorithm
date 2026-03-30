// Task 2
#include <iostream>
using namespace std;
void findPattern(char text[], char pattern[]) {
    int n = 0, m = 0;
    while (text[n] != '\0') n++;
    while (pattern[m] != '\0') m++;

    bool found = false;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            if (!found) {
                found = true;
            }
            cout << "Pattern found at index: ";
            cout << i << " "<<endl;
        }
    }

    if (!found) {
        cout << "Pattern not found in the text.";
    }

    cout << endl;
}

int main() {
    char text[200], pattern[100];

    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern: ";
    cin >> pattern;

    findPattern(text, pattern);

    return 0;
}
