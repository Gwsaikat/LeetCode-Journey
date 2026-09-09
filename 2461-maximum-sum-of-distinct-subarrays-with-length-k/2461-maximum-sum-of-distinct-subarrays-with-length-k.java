import java.util.HashSet;
import java.util.Set;

class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        long currentSum = 0;
        long maxSum = 0;
        int st = 0;

        for (int end = 0; end < nums.length; end++) {
            while (set.contains(nums[end])) {
                set.remove(nums[st]);
                currentSum -= nums[st];
                st++;
            }

            set.add(nums[end]);
            currentSum += nums[end];

            if (end - st + 1 > k) {
                set.remove(nums[st]);
                currentSum -= nums[st];
                st++;
            }

            if (end - st + 1 == k) {
                maxSum = Math.max(maxSum, currentSum);
            }
        }

        return maxSum;
    }
}