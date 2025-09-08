lass Solution {
private:    
    ListNode* merge(ListNode* first, ListNode* second){
        ListNode dummy(0);
        ListNode* temp = &dummy;
        
        while(first && second){
            if(first->val < second->val){
                temp->next = first;
                first = first->next;
            }
            else{
                temp->next = second;
                second = second->next;
            }
            temp = temp->next;
        }

        if(first != NULL)
            temp->next = first;
        else
            temp->next = second;

        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        //divide the list in 2 parts then MERGE-SORT
        if(!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL; //break the list
        ListNode* secondHalf = slow;

        return merge(sortList(head),sortList(secondHalf));

    }
};