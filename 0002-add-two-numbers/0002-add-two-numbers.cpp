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
    void MakeAnswerNode(ListNode* node, ListNode* l1, ListNode* l2, bool ten)
    {
        if (nullptr == node)
            return;

        if(false == ten && nullptr == l1 && nullptr == l2)
            return;
        
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

        if(true == ten)
            sum++;

        int val = sum % 10;
        sum /= 10;
        ListNode* nextNode = new ListNode(val);
        node->next = nextNode;

        MakeAnswerNode(nextNode, l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, sum);
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val);

        int val = sum % 10;
        ListNode* node = new ListNode(val);
        sum /= 10;
        
        MakeAnswerNode(node, l1->next, l2->next, sum);

        return node;
    }
};