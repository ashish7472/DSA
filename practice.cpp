#include<bits/stdc++.h>
using namespace std;

bool binary(vector<int>& arr, int s, int e, int n, int key){
    if(s>e) return false;

    int m = (s+e)/2;
    if(arr[m]==key) return true;

    return binary(arr,s,m-1,n,key) || binary(arr,m+1,e,n,key);
}

int main()
{
    vector<int>arr = {1,2,3,4,3,2,1,0};
    int n = arr.size();
    int s = 0, e = n-1;
    int key = 10;
    cout<<binary(arr,s,e,n,key);
    return 0;
}