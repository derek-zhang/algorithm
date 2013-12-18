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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode *first = head;
        ListNode *second = head->next->next;
        while(first && second) {
            if (first == second) return true;
            first = first->next;
            if (!second->next) return false;
            second = second->next->next;  // 走两步
        }
        return false;
    }
};

/*
还有简洁点的写法
*/
