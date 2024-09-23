#include<iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;  //min heap ke case me smallest ho jayega
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[left]>arr[largest])
        largest = left;
    if(right<=n && arr[right]>arr[largest])
        largest = right;
    
    if(largest!=i){ //matlab largest update ho chuka h
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
int main()
{
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }

    cout<<"Max Heap: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}