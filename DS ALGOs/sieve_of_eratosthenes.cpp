#include<iostream>
#include <vector>
using namespace std;

//by using this algo we don't get tle(time limit exceeded error in prime no. calculation) which is caused by high time complaxity

int main()
{
    int count = 0,n;
    cin>>n;
    vector<bool>prime(n+1,true);
    prime[0] = prime[1] = false;
    for(int i=2;i<n;i++){
        if(prime[i]){
            count++;
            for(int j=i*2;j<n;j=j+i){
                prime[j]=0;
            }
        }
    }
    cout<<count;

    return 0;
}