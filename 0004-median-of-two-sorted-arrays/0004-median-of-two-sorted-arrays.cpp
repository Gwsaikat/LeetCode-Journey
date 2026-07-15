class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m) return findMedianSortedArrays(nums2, nums1);
        
        int low = 0;
        int high = n;
        // 1. Fixed operator precedence with parentheses
        int lefttotalnum = (n + m + 1) / 2;
        
        while (low <= high) {
            int midn = (low + high) >> 1;
            int midm = lefttotalnum - midn;
            
            int leftn1 = INT_MIN, leftm2 = INT_MIN;
            int rightm1 = INT_MAX, rightn2 = INT_MAX;
            
            // 2. Updated leftn1 and leftm2 with actual values before comparison
            if (midn > 0) leftn1 = nums1[midn - 1];
            if (midm > 0) leftm2 = nums2[midm - 1];
            
            if (midn < n) rightm1 = nums1[midn];
            if (midm < m) rightn2 = nums2[midm];
            
            if (leftn1 <= rightn2 && leftm2 <= rightm1) {
                // 3. Handled correct odd/even return logic based on merged size (n + m)
                if ((n + m) % 2 == 1) return max(leftn1, leftm2);
                // 4. Fixed undeclared 'rightm2' identifier to 'rightn2'
                return ((double)max(leftn1, leftm2) + min(rightm1, rightn2)) / 2.0;
            } 
            else if (leftn1 > rightn2) {
                high = midn - 1;
            } 
            else {
                // 5. Fixed logic bug by turning this into a proper 'else' statement
                low = midn + 1;
            }
        }
        return 0;
    }
};