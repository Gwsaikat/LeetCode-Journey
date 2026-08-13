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
    bool isPalindrome(vector<int>nodeVal){
        int i = 0 ;
        int j = nodeVal.size() - 1;

        while ( i <= j ){
            if ( nodeVal[i] != nodeVal[j] ) return false;
            i++;
            j--;
        }

        return true;
    }

    bool isPalindrome(ListNode* head) {
        vector<int>nodeVal;
        ListNode* curr = head;

        while (curr != NULL){
            nodeVal.push_back(curr->val);
            curr = curr->next;
        }

        return isPalindrome(nodeVal);
    }
};