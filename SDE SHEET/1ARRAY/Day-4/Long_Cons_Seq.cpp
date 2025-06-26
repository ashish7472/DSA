//Longest consecutive sequence
//Sorting(Better) approach
#include<bits/stdc++.h>
using namespace std;

int lse(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());

    int longest = 1, cnt = 1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]) continue; //skip duplicates
        if(arr[i] == arr[i-1]+1){
            cnt++;
        }
        else{
            cnt = 1;
        }
        longest = max(longest,cnt);
    }

    return longest;  
}

int main()
{
    vector<int> arr = {100, 200, 1, 2, 3, 4};
    int ans = lse(arr);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}