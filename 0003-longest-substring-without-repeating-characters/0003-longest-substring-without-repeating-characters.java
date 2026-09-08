import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> lastSeen = new HashMap<>();
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); ++end) {
            char ch = s.charAt(end);

            if (lastSeen.containsKey(ch) && lastSeen.get(ch) >= start) {
                start = lastSeen.get(ch) + 1;
            }

            lastSeen.put(ch, end);
            maxLength = Math.max(maxLength, end - start + 1);
        }

        return maxLength;
    }
}