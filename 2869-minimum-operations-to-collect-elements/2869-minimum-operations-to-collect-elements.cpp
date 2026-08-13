#include <vector>
#include <unordered_set>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::unordered_set<int> collected;
        int operations = 0;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            operations++;
            
            if (nums[i] <= k) {
                collected.insert(nums[i]);
            }
            
            if (collected.size() == k) {
                return operations;
            }
        }
        
        return operations;
    }
};