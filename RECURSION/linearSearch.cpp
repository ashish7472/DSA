#include<iostream>
using namespace std;

bool isPresent(int *arr, int n, int key){
    if(!n && key != arr[n])
        return false;
    else if(key==arr[n])
        return true;
    else{
        return isPresent(arr,n-1,key);
    }
}

int main()
{
    int arr[5] = {3,5,1,2,6};
    int n = 5;
    int key = 2;
    bool check = isPresent(arr,n,key);
    if(check)
        cout<<"Present";
    else
        cout<<"Not Present";
    return 0;
}