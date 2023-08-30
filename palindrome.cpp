#include<iostream>
using namespace std;

bool palindrome(int size,int arr[]){
    bool check;
        for(int i=0;i<size/2;i++){
            check = 0;
            if(arr[i]==arr[size-1-i]){
                check = 1;
            }
            else
                check = 0;
            return check;

        }
}

int main()
{
    int size,arr[1000];
    bool check;
    cout<<"size: ";
    cin>>size;
    cout<<"elements: ";
    for(int i=0;i<size;i++)
        cin>>arr[i];
    
    check = palindrome(size,arr);
    if(check == 1)
        cout<<"It is a palindrome number.";

    else
        cout<<"It is not a palindrome number.";

    
    return 0;
}