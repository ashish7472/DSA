#include <iostream>
using namespace std;
main(){
    int size,arr[1000];
    cout<<"size: ";
    cin>>size;
    cout<<"elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    for(int i=1;i<size;i++){
        int temp = arr[i];
        int j;
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp)
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1] = temp;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}