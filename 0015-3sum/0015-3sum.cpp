class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>triplet ;
        int n = nums.size();
        int target = 0 ;

        sort(nums.begin(),nums.end());

        for ( int i = 0 ; i < n-2 ; ++i ){
            if ( i > 0 && nums[i] == nums[i-1] ) continue ;

            int j = i+1 ;
            int k = n-1 ;

            while ( j < k ){
                int currentSum = nums[i]+nums[j]+nums[k];

                if ( currentSum == target ){
                    triplet.push_back({nums[i],nums[j],nums[k]});
                        while ( j < k && nums[j] == nums[j+1]) j++ ;
                        while ( j < k && nums[k] == nums[k-1]) k-- ;
                    j++ ;
                    k-- ;
                } 
                    else if ( currentSum < target ){
                        j ++ ;
                } else {
                    k -- ;
                }
            }
        }
            return triplet ;
    }
};