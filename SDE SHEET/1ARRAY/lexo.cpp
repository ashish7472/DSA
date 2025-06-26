#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[] = {1,3,2,4,9,0,5};
    next_permutation(arr, arr+7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}