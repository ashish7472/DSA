#include <iostream>
using namespace std;

main(){
    int size,arr[1000];
    cout<<"size: ";
    cin>>size;
    cout<<"elements: ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(arr[j+1]<arr[j])
                swap(arr[j+1],arr[j]);
        }
    }
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
}