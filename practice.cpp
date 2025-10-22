#include<iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(){val = 0, next = NULL;}
        Node(int val){this->val = val, next = NULL;}
};

Node* make_ll(Node*& head){
    int val;
    cout<<"Enter val: ";
    cin>>val;
    if(val == -1) return NULL;
    head = new Node(val);

    head->next = make_ll(head->next);

    return head;
}

int main()
{
    Node* head = NULL;

    head = make_ll(head);

    Node* temp = head;
    while(temp){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}