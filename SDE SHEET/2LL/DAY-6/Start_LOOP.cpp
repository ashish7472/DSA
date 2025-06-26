// Function to find the first node of loop in ll
Node* firstNode(Node* head) {
    Node* slow = head;  
    Node* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) {
        
        slow = slow->next;        
        fast = fast->next->next;  

        // a loop is detected
        if (slow == fast) {
             // Reset the slow pointer
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) {
                slow = slow->next;  
                fast = fast->next;  
                // When slow and fast meet again,
                // it's the first node of the loop
            }
            
            // Return the first node of the loop
            return slow;  
        }
    }
    
     // If no loop is found, return NULL
    return NULL; 
}