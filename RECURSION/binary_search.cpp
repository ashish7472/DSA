#include<iostream>
using namespace std;

bool binarySearch(int *arr,int size,int s,int e,int key){
    int m = (s+e)/2;
    if(s>e)
        return false;
    if(arr[m]==key)
        return true;
    if(arr[m]>key)
        return binarySearch(arr,size,s,m-1,key);
    else
        return binarySearch(arr,size,m+1,e,key);
}

int main()
{
    int arr[6] = {2,4,6,10,14,16};
    int size = 6;
    int key = 16;
    int s = 0;
    int e = size-1;
    bool check = binarySearch(arr,size,s,e,key);
    if(check)
        cout<<"Present";
    else    
        cout<<"Not Present";
    return 0;
}