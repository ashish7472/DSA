#include<bits/stdc++.h>
using namespace std;

int lse(vector<int>& arr){
    int n = arr.size();
    unordered_set<int>st;

    for(auto it : arr){
        st.insert(it);
    }

    int longest = INT_MIN;
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;

            while(st.find(it+1) != st.end()){
                cnt++;
                it++;
            }
            longest = max(longest,cnt);
        }
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