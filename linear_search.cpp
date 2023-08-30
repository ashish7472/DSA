#include <iostream>
using namespace std;

int linear_search(int n,int arr[],int size){
    for(int i=0;i<size;i++){
        if(arr[i]==n){
            return i;
        }
        
    }return 0;
    
}

main(){
    int n,arr[100],size;
    cout<<"enter your number: ";
    cin>>n;
    cout<<"enter size of array: ";
    cin>>size;
    cout<<"enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    
    if(linear_search(n,arr,size)==0)
        cout<<"Element is absent";
    else 
        cout<<"Element is present";
    
    

}