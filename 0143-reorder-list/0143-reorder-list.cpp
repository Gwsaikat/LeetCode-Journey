class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        stack<ListNode*> nodes;
        ListNode* curr = head;

        while (curr) {
            nodes.push(curr);
            curr = curr->next;
        }

        int count = nodes.size();
        curr = head;

        for (int i = 0; i < count / 2; i++) {
            ListNode* topNode = nodes.top();
            nodes.pop();

            ListNode* nextTemp = curr->next;
            curr->next = topNode;
            topNode->next = nextTemp;

            curr = nextTemp;
        }

        curr->next = nullptr;
    }
};