#include <iostream>
using namespace std;

int firstOcc(int arr[],int size,int key){
    int start = 0,end = size-1,mid = (start+end)/2,ans = -1;
    for(int i=0;i<size;i++){
        if(key == arr[mid]){
            ans = mid;
            end = mid-1;
        }
        else if(key > arr[mid]){
            start = mid+1;
        }
        else
            end = mid-1;

        mid = (start+end)/2;
    }
    return ans;

}

int lastOcc(int arr[],int size,int key){
    int start = 0,end = size-1,mid = (start+end)/2,ans = -1;
    for(int i=0;i<size;i++){
        if(key == arr[mid]){
            ans = mid;
            start = mid+1;
        }
        else if(key > arr[mid]){
            start = mid+1;
        }
        else
            end = mid-1;

        mid = (start+end)/2;
    }
    return ans;

}

main(){
    //arr is already sorted in increasing order and it can contain duplicate numbers.
    int size,arr[100],key;
    cout<<"enter the size of array: ";
    cin>>size;
    cout<<"enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"enter key: ";
    cin>>key;
    cout<<"first occ of key is at index: "<<firstOcc(arr,size,key)<<endl;
    cout<<"last occ of key is at index: "<<lastOcc(arr,size,key);
}