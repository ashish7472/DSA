class compare{
    public: 
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, compare>minHeap;
        ListNode* newHead = NULL;
        ListNode* temp = newHead;

        for(int i=0;i<k;i++){
            if(lists[i]){
                ListNode* tmp = lists[i];
                minHeap.push(tmp);
            }
        }

        while(!minHeap.empty()){
            ListNode* curr = minHeap.top();
            minHeap.pop();
            ListNode* newnode = new ListNode(curr->val);
            if(newHead==NULL){
                newHead = temp = newnode;
                temp->next = NULL;
            }
            else{
                temp->next = newnode;
                temp = temp->next;
            }

            if(curr->next){
                ListNode* tmp = curr->next;
                minHeap.push(tmp);
            }
        }

        return newHead;
    }
};