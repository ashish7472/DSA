#include <iostream>
using namespace std;

int binarySearch(int arr[],int size,int key){
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    while(start<=end){
        if(key == arr[mid]){
            return mid;
        }
        else if(key>arr[mid])
            start = mid+1;
        else
            end = mid-1;
        
        mid = (start+end)/2;
    }
    return -1;

}

main(){
    cout<<"Name: ASHISH ROLAN";
    cout<<"Roll No: 22103033";
    int size,arr[100],key;
    cout<<"enter size of array: ";
    cin>>size;
    cout<<"enter elements in array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"enter key to search in array: ";
    cin>>key;
    cout<<"the element is at index: "<<binarySearch(arr,size,key);

}