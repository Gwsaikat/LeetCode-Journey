class Solution {
public:
    int t[21][21];

    bool solve(int i, int j, const string& s, const string& p) {
        // Basic Check for Initial validation
        if (j == p.length()) {
            return i == s.length();
        }
        
        if (t[i][j] != -1) return t[i][j];
        
        // Check If the first char match or not ?
        bool first_char_match = false;
        if (i < s.length() && (s[i] == p[j] || p[j] == '.')) {
            first_char_match = true;
        }
        
        // Skip or Take logic 
        if (j + 1 < p.length() && p[j + 1] == '*') {
            bool not_take = solve(i, j + 2, s, p);
            bool take = first_char_match && solve(i + 1, j, s, p);
            
            return t[i][j] = not_take || take;
        }
        
        // If no * then
        return t[i][j] = first_char_match && solve(i + 1, j + 1, s, p);
    }
    
    bool isMatch(string s, string p) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, s, p);
    }
};