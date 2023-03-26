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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempB = headB;
        while(headA){
            ListNode* tempB = headB;
            while(tempB){
                if(tempB == headA) return headA;
                tempB = tempB->next;
            }
            headA=headA->next;
        }
        return NULL;
    }
};