#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> charMap(128, -1); // Maps ASCII char -> last seen index
        int left = 0;
        int maxLen = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            if (charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }
            charMap[s[right]] = right;
            maxLen = std::max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};