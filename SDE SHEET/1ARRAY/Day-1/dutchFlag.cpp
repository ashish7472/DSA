#include<iostream>
using namespace std;

int main()
{
    int arr[] = {2,0,2,1,1,0,2,0,1,0,2,2,0,0,1,0,2};
    int n = 17;

    int s = 0;
    int e = n-1;
    int m = 0;

    while(m<=e){
        if(arr[m]==0){
            swap(arr[s],arr[m]);
            s++, m++;
        }
        else if(arr[m]==1)
            m++;
        else{    
            swap(arr[e],arr[m]);
            e--;
        }
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<", ";
    }
    return 0;
}