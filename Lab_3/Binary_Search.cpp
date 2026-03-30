//Task 1
#include <iostream>
#include <cstdlib>
using namespace std;

int binary_search(int array[], int n, int target){
    int st = 0, end = n-1, mid=0;
    while(st <= end){
        mid = (st + (end-st))/2;
        
        if(target > array[mid]){
            st = mid + 1;
        }else if(target < array[mid]){
            end = mid -1;
        }else{
            return mid;
        }
    }
    return -1;
    
}
int main() {
    int n;
    cout<<"Enter array size: "<<endl;
    cin>>n;
    int array[n];
    for(int i =0; i<n; i++){
        array[i] = rand() % 100;
    }
    for(int i =0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j] > array[j +1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    for(int a: array){
        cout<<a<<" ";
    }
    cout<<endl;
    int target; 
    cout<<"Enter target value: ";
    cin>>target;
    if(binary_search(array,n,target) != -1){
        cout<<binary_search(array,n,target);
    }else{
        cout<<"Not found !"<<endl;
    }
    return 0;
}