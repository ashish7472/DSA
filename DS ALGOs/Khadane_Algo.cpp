#include<iostream>
using namespace std;

int main()
{
    int arr[] = {3,-2,-1,5};
    int n = 4;
    int maxi = INT16_MIN;

    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxi = max(sum,maxi);
        }
    }

    cout<<maxi<<endl;

    return 0;
}