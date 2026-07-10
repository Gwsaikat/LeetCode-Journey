#include <vector>
#include <algorithm>

class Solution {
public:
    void findCombinations(int index, int target, std::vector<int>& candidates, 
                          std::vector<int>& current, std::vector<std::vector<int>>& result) {
        // Base Case 1: If target is met, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base Case 2: Out of bounds or target went negative
        if (index == candidates.size() || target < 0) {
            return;
        }

        // Choice 1: Include the current element
        // (We don't increment the index because the same element can be reused)
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(index, target - candidates[index], candidates, current, result);
            current.pop_back(); // Backtrack
        }

        // Choice 2: Exclude the current element and move to the next one
        findCombinations(index + 1, target, candidates, current, result);
    }

    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        // Sorting helps prune unnecessary recursive branches early
        std::sort(candidates.begin(), candidates.end());
        
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};