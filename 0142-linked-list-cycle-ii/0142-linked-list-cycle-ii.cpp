/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){ // its means their is a cycle exists
                slow = head;
                while(slow!=fast){ //whenever slow == fast then present node is starting node of cycle
                    slow = slow->next;
                    fast = fast->next;
                    
                }
                return slow;
            }
        }
        return NULL;
    }
};