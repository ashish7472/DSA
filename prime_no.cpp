#include <iostream>
using namespace std;
main(){
    int n;
    cout<<"enter an number: ";
    cin>>n;
    for(int i=2;i<n;i++){
        if(n%i != 0){
            cout<<"Prime Number.";
            break;
        }else
            cout<<"Not a Prime Number.";
            break;
    }
}