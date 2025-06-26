//MOST OPTIMAL SOLUTION FOR 3-SUM PROBLEM
#include<bits/stdc++.h>
using namespace std;

void sum3(vector<vector<int>>& ans, vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue; // skip duplicates in i side
        //i>0 is helper condition ki wo 0th ele h to ok but baki walo ke liye duplicates check karo

        int j = i + 1, k = n - 1; //left and right pointers
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];

            if(sum == 0){
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1]) j++; // skip duplicates in j side
                while(j < k && arr[k] == arr[k+1]) k--; // skip duplicates in k side
            }
            else if(sum < 0) j++;
            else k--;
        }
    }
}

int main()
{
    vector<int>arr = {-1,0,1,2,-1,-4};
    vector<vector<int>>ans;

    sum3(ans, arr);
    for(auto it : ans){
        for(auto jt : it){
            cout<<jt<<" ";
        }cout<<endl;
    }
    return 0;
}