class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string beautiful = "";
        int minLen = INT_MAX;
        int n = s.size();

        for (int start = 0; start < n; ++start) {
            int count1 = 0;
            for (int end = start; end < n; ++end) {
                if (s[end] == '1') {
                    count1++;
                }

                if (count1 == k) {
                    string sub = s.substr(start, end - start + 1);
                    int len = sub.length();

                    if (len < minLen) {
                        minLen = len;
                        beautiful = sub;
                    } else if (len == minLen && sub < beautiful) {
                        beautiful = sub;
                    }
                    
                    break;
                }
            }
        }

        return beautiful;
    }
};