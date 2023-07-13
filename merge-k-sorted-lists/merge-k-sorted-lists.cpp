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
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start + 1 == end) {
            return merge(lists[start], lists[end]);
        }
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }

    
    ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode* temp = new ListNode(-1);
    ListNode* curr = temp;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    if (l1) {
        curr->next = l1;
    } else if (l2) {
        curr->next = l2;
    }

    return temp->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = lists.size();
    if (k == 0) return NULL;
    if (k == 1) return lists[0];

    ListNode* ans = lists[0];
    for (int i = 1; i < k; i++) {
        ans = merge(ans, lists[i]);
    }

    return ans;
}

};