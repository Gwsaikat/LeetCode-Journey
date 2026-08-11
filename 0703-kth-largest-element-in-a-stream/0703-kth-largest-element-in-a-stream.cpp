class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kSize;

public:
    KthLargest(int k, vector<int>& nums) {
        kSize = k;
        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        
        if (minHeap.size() > kSize) {
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};