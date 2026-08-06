class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>totalCount(128,0);
        for ( char ch : t ){
            totalCount[ch]++ ;
        }

        int left = 0;
        int right = 0;
        int StartIdx = 0;
        int requiredCount = t.size();
        int minWindow = INT_MAX;

        while ( right <= s.size()){
            if ( totalCount[s[right]] > 0 ){
                requiredCount -- ;
            }

            totalCount[s[right]] -- ;
            right ++ ;

            while ( requiredCount == 0 ){
                if ( right - left < minWindow ){
                    minWindow = right - left;
                    StartIdx = left;
                }

                totalCount[s[left]] ++ ;
                if ( totalCount[s[left]] > 0 ){
                    requiredCount ++ ;
                }

                left ++ ;
            }

        }

        return minWindow == INT_MAX ? "" : s.substr(StartIdx , minWindow);
    }
};