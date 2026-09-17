class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false; 
        
        vector<int> mp(26, 0);
        
        for (char ch : s) mp[ch - 'a']++;
        for (char ch : t) mp[ch - 'a']--;
        
        for (int val : mp) {
            if (val != 0) return false;
        }
        
        return true;
    }
};