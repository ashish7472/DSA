#include<iostream>
#include<algorithm>
using namespace std;

int last(int arr[], int n, int key, int s, int e){
    int ans=-1;
    int m;
    while(s<=e){
        m = (s+e)/2;
        if(arr[m]==key){
            ans = m;
            s = m+1;
        }
        else if(arr[m]<key){
            s = m+1;
        }
        else{
            e = m-1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1,2,3,4,4,5,6,7};
    int n = 8;
    int s = 0;
    int e = n-1;
    int key = 4;
    cout<<last(arr,n,key,s,e);
    return 0;
}