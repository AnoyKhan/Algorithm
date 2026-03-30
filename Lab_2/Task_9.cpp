#include <iostream>
using namespace std;
int main() {
    char str1[100], str2[100];

    cout << "Enter String 1: ";
    cin >> str1;

    cout << "Enter String 2: ";
    cin >> str2;

    int i = 0;
    int result = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            result = str1[i] - str2[i];
            break;
        }
        i++;
    }
    if (result == 0) {
        if (str1[i] == '\0' && str2[i] == '\0')
            result = 0;
        else if (str1[i] == '\0')
            result = -1;
        else
            result = 1;
    }
    if (result == 0)
        cout << "Result = 0 ( "<<str1<<" & " <<str2<<"are equal)" << endl;
    else if (result > 0)
        cout << "Result = 1 ( "<<str1<<" > "<< str2<<" )" << endl;
    else
        cout << "Result = -1 ( "<<str1 <<" < " <<str2<<" )" << endl;

    return 0;
}
