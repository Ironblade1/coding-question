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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> d;
        for(int i=0;i<lists.size();i++){
            ListNode* temp = lists[i];
            while(temp){
                d.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(d.begin(),d.end());
        for(auto i:d){
            cout<<i<<",";
        }
        
        ListNode* ans = new ListNode(0);
        ListNode* tempAns = ans;
        for(int i:d){
            
            ListNode* temp = new ListNode(i);
            tempAns->next = temp;
            tempAns = tempAns->next;
        }
        return ans->next;
    }
    
};