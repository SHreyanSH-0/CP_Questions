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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* node = head;
        ListNode* prev = nullptr;
        vector<int> ans = {(int)1e8,0};

        int first_critical = -1, prev_critical = -1;
        int i = 0;
        while(node){
            ListNode* next = node->next;
            if(prev != nullptr && next != nullptr){
                if((prev->val < node->val && next->val < node->val) || (prev->val > node->val && next->val > node->val)){
                    if(first_critical == -1){
                        first_critical = i;
                        prev_critical = i;
                    }
                    else{
                        ans[0] = min(ans[0],i - prev_critical);
                        ans[1] = i - first_critical ;
                        prev_critical = i;
                    }
                }
            }

            prev = node;
            node = node->next;
            i++;
        }
        if(ans[0] == 1e8) return {-1,-1};
        return ans;
    }
};