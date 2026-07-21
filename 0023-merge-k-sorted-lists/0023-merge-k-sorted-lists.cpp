class Solution {
public:
    // Custom Comparator to sort nodes by value
    struct Comparator {
        bool operator()(ListNode* const& p1, ListNode* const& p2) {
            return p1->val > p2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> min_heap;

        for (ListNode* node : lists) {
            if (node) min_heap.push(node);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (!min_heap.empty()) {
            ListNode* topNode = min_heap.top();
            min_heap.pop();

            curr->next = topNode;
            curr = curr->next;

            if (topNode->next) {
                min_heap.push(topNode->next);
            }
        }

        return dummy->next;
    }
};