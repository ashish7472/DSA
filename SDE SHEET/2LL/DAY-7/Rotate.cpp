//OPTIMAL SOL

node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;

    //calculating length
    node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }

    //link last node to first node to make ll circular
    temp->next = head;

    k = k%length; //when k is more than length of list

    int end = length-k; //to get end of the list from where we've to break the link
    while(end--) temp = temp->next;
    
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
}