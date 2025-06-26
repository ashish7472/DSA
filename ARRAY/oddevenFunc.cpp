#include <iostream>
using namespace std;

string isEven(int a){  //function for odd, even.
    if(a&1==1){
        return "Odd";
    }
    else
        return "Even";
}

main(){
    int num;
    cout<<"enter a number: ";
    cin>>num;
    string ans = isEven(num);     //storing return value of the function. 
    cout<<ans;
}