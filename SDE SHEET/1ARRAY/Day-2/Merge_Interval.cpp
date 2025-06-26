#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size();

    sort(arr.begin(),arr.end());

    vector<vector<int>>ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(ans.back()[1]>=arr[i][0]){
            ans.back()[1] = max(ans.back()[1],arr[i][1]);
        }
        else{
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

