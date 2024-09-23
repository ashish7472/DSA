#include<iostream>
using namespace std;

bool isPalindrome(string str, int i, int j){
    if(i>j)
        return true;
    else if(str[i] != str[j])
        return false;
    else 
        return isPalindrome(str,i+1,j-1);
}

int main()
{
    string str = "abbccbba";
    bool check = isPalindrome(str,0,str.size());
    
    if(check==1)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}