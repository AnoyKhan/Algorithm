#include <iostream>
using namespace std;
int main() {
    int n, high, low, mid,key;
    
    cout<<"Enter Array Size: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter Sorted element: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter element to search: ";
    cin>>key;
    
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low + high) /2;
        if(arr[mid] == key){
            cout<<"Element found at index no: "<<mid;
            return 0;
        }else if(arr[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }cout<<"Element not found!";
    return 0;
}
