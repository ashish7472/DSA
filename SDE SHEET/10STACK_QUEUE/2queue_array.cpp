#include<iostream>
using namespace std;

//ENQUEUE OPERATION IN QUEUE.
int main()
{
    char choice;
    int n;
    int queue[100];
    int f=-1,r=-1;
    cout<<"enter the size of queue: ";
    cin>>n;
    do{
        int data;
        cout<<"enter the data for enqueue: ";
        cin>>data;
        if(r==n-1){
            cout<<"overflow!"<<endl;
            break;
        }
        else if(f==-1 && r==-1){
            f++,r++;
            queue[r]=data;
        }
        else{
            r++;
            queue[r]=data;
        }
    
    cout<<"Do you want to continue[y/n]: ";
    cin>>choice;
        
    }while(choice=='y');

    cout<<"QUEUE:=>";
    int i = f;
    while(i != r+1){
        cout<<queue[i]<<" ";
        i++;
    }
    
    return 0;
}

// FOR DEQUEUE OPERATION-->

// if(f==-1 && r==-1)
//     cout<<"underflow";
// else if(f==r)
//     f = r = -1;
// else
//     f++;