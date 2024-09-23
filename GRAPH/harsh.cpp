// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>arr = {9,52,25,14,41};
    sort(arr.begin(),arr.end(),[](int a, int b){
        string s1 = to_string(a);
        string s2 = to_string(b);
        return s1+s2>s2+s1;
    });
    
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   

    return 0;
}