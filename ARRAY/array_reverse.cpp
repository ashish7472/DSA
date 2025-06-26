#include <iostream>
using namespace std;
main(){
    int arr[100],size;
    cout<<"enter the size of array: ";
    cin>>size;
    cout<<"enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Array before reversing: "<<endl;
    cout<< "[ ";
    for(int i=0;i<size;i++){
        cout<<arr[i] << " ";
    }cout<<"]" <<endl;

    cout<<"Array after reversing: "<<endl;
    cout<< "[ ";
    for(int i=(size-1);i>=0;i--){
        cout<<arr[i] << " ";
    }cout<<"]" <<endl;

}