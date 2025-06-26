#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

int main()
{
    Node *head = NULL;
    Node* temp = head;
    bool ch;
    int n;
    do{
        Node* newnode = new Node;
        newnode->next = NULL;
        cout<<"ente Number: ";
        cin>>n;
        newnode->data = n;
        if(head == NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
        }

        cout<<"DYW: ";
        cin>>ch;
    }while(ch);

    temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<endl;

    int newn = 5;
    Node* tempn = new Node;
    tempn->data = newn;
    tempn->next = head;
    head = tempn;

    temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    
    return 0;
}