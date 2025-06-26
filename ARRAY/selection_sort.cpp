#include <iostream>
using namespace std;

main(){
    int size,arr[1000];
    cout<<"size: ";
    cin>>size;
    cout<<"elements: ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    
    for(int i=0;i<size-1;i++){
        int minIndex = i;

        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex],arr[i]);
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    
}

