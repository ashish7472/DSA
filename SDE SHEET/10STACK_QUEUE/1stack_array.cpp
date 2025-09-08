#include<iostream>
using namespace std;

int main()
{
    char choice;
    int size;
    int stack[100];
    cout<<"enter size of stack: ";
    cin>>size;
    int top = -1;

    do{
    int data;
    cout<<"enter data you want to add in stack: ";
    cin>>data;
    if(top==size-1){
        cout<<"overflow!"<<endl;
        break;
    }
    else{
        top++;
        stack[top]=data;
        cout<<"Do you want to add more data in the stack[y/n]: ";
        cin>>choice;
    }

    }while(choice=='y');
    
    cout<<"STACK:-> ";
    for(int i=0;i<size;i++)
        cout<<stack[i]<<" ";

    cout<<endl;

    
    // POPING UP ITEM FROM THE STACK
    int item = stack[top];
    cout<<"Deleted item from the stack:-> "<<item;
    top--;
    cout<<endl;

    //DATA LEFT OUT AFTER DELETION OF ONE ITEM FROM THE STACK.
    for(int i=top;i>=0;i--)
        cout<<stack[top]<<" ";

    return 0;
}