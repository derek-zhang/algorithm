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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *root = NULL;  // 单分配root，然后赋值，原head保留遍历用。
        // 二重指针方式，处理head置空  
        // https://github.com/missjing/leetcode/blob/master/Remove%20Duplicates%20from%20Sorted%20ListII.txt
        // 不要忘记释放删除的节点
        ListNode **j = &root;
        while (head) {
            if (head->next == NULL || head->next->val != head->val) {
                *j = head;
                j = &(head->next);
                head = head->next;
            } else {
                /*
                 * 相等就直到找到不相等的点为止
                 */
                int val = head->val;
                while (head && head->val == val) {
                    ListNode *del = head;
                    head = head->next;
                    delete del;
                }
            }
        }
        *j = NULL;
        return root;
    }
    /*
    分配假头结点的方式，避免处理要把head置空的复杂。不然如果要把head置空，必然用二重指针了
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        ListNode *dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode *j = dummy;
        bool dup = false;
        ListNode *i = dummy->next;
        while (i) {
            int val = i->val;
            while (i->next && i->next->val == val) {
                ListNode *tmp = i;
                dup = true;
                i = i->next;
                delete tmp;
            }
            if (dup) {
                ListNode *tmp = i;
                i = i->next;
                delete tmp;
                dup = false;
                continue;
            }

            j->next = i;
            j = j->next;
            i = i->next;
            dup = false;
        }
        j->next = i;
        ListNode *tmp = dummy->next;
        delete dummy;
        return tmp;
    }
    */
    /*
    不分配假头结点，像下面这样，是没法处理head需要置空的情况的。[1-1-1-1]
        ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        
        ListNode *j = head;
        int head_val = head->val;
        bool dup = false;
        for (ListNode *i = head->next; i != NULL; i = i->next) {
            if (j->val == i->val) {
                dup = true;                
            } else {
                if (dup) {
                    j->val = i->val;
                    dup = false;
                } else {
                    j = j->next;
                    j->val = i->val;
                }
            }
        }
        //if (j == head && j->val == head_val) return NULL;
        if (dup && j == head) return NULL;
        if (dup)
            j = NULL;
        else
            j->next = NULL;
    
        return head;
    }
    */
};
