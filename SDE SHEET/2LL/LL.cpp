#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;
};

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}

void make(Node*& head){
    Node* newnode = NULL;
    Node* temp = head;
    int n;
    cout<<"No. of Nodes: ";
    cin>>n;

    while(n--){
        int val;
        cout<<"Enter Val:";
        cin>>val;

        newnode = new Node;
        newnode->val = val;
        newnode->next = NULL;
        if(head==NULL){
            temp = head = newnode;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
        }
    }
}


int main()
{
    Node* head = NULL;
    make(head);
    print(head);
    return 0;
}