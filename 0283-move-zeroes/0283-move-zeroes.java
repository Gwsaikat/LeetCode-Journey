class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;

        for (int num : nums) {
            if (num != 0) {
                nums[j++] = num;
            }
        }

        while (j < nums.length) {
            nums[j++] = 0;
        }
    }
}