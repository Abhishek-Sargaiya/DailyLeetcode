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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> s;
        ListNode* curr = head;

        while(curr != NULL){
            while(!s.empty() && s.top()->val < curr->val)   s.pop();

            s.push(curr);
            curr = curr->next;
        }
        ListNode* select = NULL;
        while(!s.empty()){
            curr = s.top();
            s.pop();
            curr->next = select;
            select = curr;
        }
        return curr;
    }
};