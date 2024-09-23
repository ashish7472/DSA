#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    if(n==0 || n==1)
        return true;
    else if(arr[0]>arr[1])
        return false;
    else{
        return isSorted(arr+1, n-1);
    }
}
int main()
{
    int arr[5] = {1,2,3,4,0};
    int n = 5;
    bool check = isSorted(arr,n);
    if(check)
        cout<<"Sorted";
    else
        cout<<"Not Sorted";
    return 0;
}