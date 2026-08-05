class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxHeap;

        for ( int num : nums ) maxHeap.push(num);

        int ans = 0;
        while ( k != 0 ){
            ans = maxHeap.top();
            maxHeap.pop();
            k-- ;
        }

        return ans;
    }
};