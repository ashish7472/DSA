#include <iostream>
using namespace std;

int totalOcc(int arr[],int size,int key){
    int count=0;
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            count++;
        }
        else
            continue;
    }
    return count;
}

main(){
    int arr[200],size,key;
    cout<<"size: ";
    cin>>size;
    cout<<"elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"key: ";
    cin>>key;
    cout<<"repetation times: "<<totalOcc(arr,size,key);

}