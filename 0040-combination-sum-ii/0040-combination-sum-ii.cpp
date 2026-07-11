class Solution {
public:
    void backtrack(vector<int>& candidates,
                   int target,
                   int index,
                   vector<vector<int>>& result, 
                   vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, result, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, result, temp);

        return result;
    }
};