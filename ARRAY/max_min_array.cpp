#include <iostream>
using namespace std;

int maxArray(int arr[],int size){
        int maxNum = INT64_MIN;
        for(int i=0;i<size;i++){
            if(arr[i]>maxNum)
                maxNum = arr[i];
        }
        return maxNum;
}

int minArray(int arr[],int size){
        int minNum = INT64_MAX;
        for(int i=0;i<size;i++){
            if(arr[i]<minNum)
                minNum = arr[i];
        }
        return minNum;
}

main(){
    int size,arr[100];
    cout<<"enter size of array: ";
    cin>>size;
    cout<<"enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<< "[ ";
    for(int i=0;i<size;i++){
        cout<<arr[i] << " ";
    }cout<<"]" <<endl;

    cout<<"Max value in array: " << maxArray(arr,size) <<endl;
    cout<<"Min value in array: " << minArray(arr,size) <<endl;
    

}