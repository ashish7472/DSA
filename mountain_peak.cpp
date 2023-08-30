#include <iostream>
using namespace std;


int mountainPeak(int arr[],int size){
    int start = 0;
    int end = size-1;
    int mid = (start+end)/2;
    while(start<end){
        if(arr[mid]<arr[mid+1]){
            start = mid+1;
        }
        else    // if arr[mid]>=arr[mid+1]
            end = mid;   //if i write e = s-1 then due to there is a chance that arr[mid]=peak by s-1 it will go in out increasing mountain slope.

        mid = (start+end)/2;
    }
    return start;
}

main(){
    int arr[200],size;
    cout<<"size: ";
    cin>>size;
    cout<<"elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Peak of mountain is at index: "<<mountainPeak(arr,size);
}