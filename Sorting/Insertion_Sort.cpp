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
    //Insertion Sort
    for(int i=1; i<n; i++){
        int key=a[i];
        int j = i -1;
        while(j>=0 && a[j]>key){
            a[j+1]= a[j];
            j--;
        }
        a[j +1] = key;
    }
    cout<<"After Insertion Sort: ";
    for(int i: a){
        cout<<i<<" ";
    }
    return 0;
}
