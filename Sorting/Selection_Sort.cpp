#include <iostream>
using namespace std;
int main() {
    int n;
    cout<<"Enter array size: ";
    cin>>n;
    int a[n];
    cout<<"Enter element: ";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for (int i =0; i<n; i++){
        int min = i;
        for(int j =0; j<n; j++){
            if(a[j]>a[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    cout<<"Array After Selection Sorting: ";
    for(int i: a){
        cout<<i<<" ";
    }
    return 0;
}
