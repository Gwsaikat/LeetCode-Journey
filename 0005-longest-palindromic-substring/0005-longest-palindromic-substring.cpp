class Solution {
public:
    int palindromecheck(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

    string longestPalindrome(string s) {
        int st = 0;
        int max_len = 0; // Track the maximum length directly

        for (int i = 0; i < s.size(); ++i) {
            int len1 = palindromecheck(s, i, i);     // Odd length palindromes
            int len2 = palindromecheck(s, i, i + 1); // Even length palindromes
            int length = max(len1, len2);

            if (length > max_len) {
                max_len = length;
                st = i - (length - 1) / 2; // Correctly shift back to the start index
            }
        }
        
        // s.substr(starting_index, length_of_substring)
        return s.substr(st, max_len); 
    }
};