#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

Node* reverse(Node* head){
	if(head==NULL || head->next == NULL)
		return head;
	Node* node = reverse(head->next);
	head->next->next = head;
	head->next = NULL;
	
}

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

	head = reverse(head);
	temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<endl;

    return 0;
}