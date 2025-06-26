#include<bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& arr){
    int n = arr.size();
    int gap = ceil((float)n/2);

    while(gap>0){
        int left = 0;
        int right = left + gap;

        while(right<n){
            if(arr[left]>arr[right]){
                swap(arr[left],arr[right]);
            }
            left++,right++;
        }
        if(gap==1) break;
        gap = ceil((float)gap/2);
    }
}

int main()
{
    vector<int> arr = {4,2,7,5,1,8};
    shellSort(arr);

    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}