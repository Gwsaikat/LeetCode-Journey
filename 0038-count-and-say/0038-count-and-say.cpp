class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string newstr = "";
            int st = 0;
            
            while (st < result.size()) {
                int end = st;
                while (end < result.size() && result[st] == result[end]) {
                    end++;
                }
                
                int freq = end - st;
                newstr += to_string(freq) + result[st];
                
                st = end;
            }
            
            result = newstr;
        }
        
        return result;
    }
};