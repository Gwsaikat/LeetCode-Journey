#include <vector>
#include <string>
#include <cctype>

class Solution {
public:
    std::vector<std::string> findWords(std::vector<std::string>& words) {
        
        int rowMap[26] = {
            1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2,
            2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2
        };

        std::vector<std::string> result;

        for (const std::string& word : words) {
            if (word.empty()) continue;

            int targetRow = rowMap[std::tolower(word[0]) - 'a'];
            bool isValid = true;

            for (char ch : word) {
                if (rowMap[std::tolower(ch) - 'a'] != targetRow) {
                    isValid = false;
                    break;
                }
            }

            if (isValid) {
                result.push_back(word);
            }
        }

        return result;
    }
};