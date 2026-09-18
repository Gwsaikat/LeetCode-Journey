class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int poisoned = 0;
        for (int i = 1; i < timeSeries.size(); ++i) {
            poisoned += min(duration, timeSeries[i] - timeSeries[i - 1]);
        }
        
        poisoned += duration;
        
        return poisoned;
    }
};