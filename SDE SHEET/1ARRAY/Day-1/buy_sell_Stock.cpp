#include<iostream>
using namespace std;

int main()
{
    int arr[] = {7,1,5,3,6,4};
    int n = 6;
    int maxProf = 0;
    int minPrice = INT16_MAX;

    for(int i=0;i<n;i++){
        minPrice = min(minPrice,arr[i]);
        maxProf = max(maxProf, arr[i]-minPrice);
    }

    cout<<maxProf;
}