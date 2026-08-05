class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Find the median element in O(n) average time
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // 2. Map normal indices to wiggle positions (odds first, then evens)
        #define A(i) nums[(1 + 2 * (i)) % (n | 1)]
        
        // 3. 3-way partition using virtual pointers
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid) {
                swap(A(i++), A(j++));
            } else if (A(j) < mid) {
                swap(A(j), A(k--));
            } else {
                j++;
            }
        }
    }
};