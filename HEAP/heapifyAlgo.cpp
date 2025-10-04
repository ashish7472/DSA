#include<iostream>
using namespace std;

//Max heap
void heapify(int arr[], int n, int i){ //heapify ka kam h ek node ko uske sahi jagah pe leke jana in heap
    int largest = i;  //min heap ke case me smallest ho jayega
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest]<arr[left]) //min heap me ye bhi change honge
        largest = left;
    if(right<=n && arr[largest]<arr[right])
        largest = right;
    
    if(largest!=i){ //matlab largest update ho chuka h
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
/*
1. hm arr ko right to left traverse karenge for making heap. pahle sare nodes tree me insert kr denge
2. CBT me nodes from index (n/2 + 1)th to nth are leaf nodes and leafs are already heap(min/max) now
we just have to check for the left over nodes.
*/
int main()
{
    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;
    for(int i=n/2;i>0;i--){  //why? explained in above comment
        heapify(arr,n,i);
    }

    cout<<"Max Heap: "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}