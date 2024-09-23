#include<iostream>
using namespace std;

int sum(int *arr,int n){
    if(n==0)
        return 0;
    else if(n==1)
        return arr[n-1];
    else{
        return arr[n-1] + sum(arr,n-1);
    }
}

int main()
{
    int arr[100];
    int n;
    cout<<"Size: ";
    cin>>n;
    cout<<"Elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"Sum: "<<sum(arr,n);
    
    return 0;
}