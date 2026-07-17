class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftpointer = 0 ;
        int rightpointer = height.size() - 1 ;
        int maxWater = 0 ;

        while ( leftpointer < rightpointer ){
            int weigth = rightpointer - leftpointer ;
            int ht = min (height[rightpointer],height[leftpointer]);
            int currentWater = ht * weigth ;

            maxWater = max (currentWater , maxWater);
            height[leftpointer] < height[rightpointer] ? leftpointer ++ : rightpointer -- ;
        }

        return maxWater ;
    }
};