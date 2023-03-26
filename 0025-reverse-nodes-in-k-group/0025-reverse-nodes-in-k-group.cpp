/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        int cnt =0;
        ListNode* curr = head;
        while(curr && cnt<k){
            curr = curr->next;
            cnt++;
        }
        if(cnt==k){
            ListNode* prev = reverseKGroup(curr,k);
            while(cnt>0){
                ListNode* frwd = head->next;
                head->next = prev;
                prev = head;
                head = frwd;
                cnt--;
            }
            head=prev;
        }
        return head;
    }
};