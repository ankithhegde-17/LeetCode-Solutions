#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        // If needle is longer than haystack, it cannot be found
        if (m > n) return -1;
        
        // Slide the window over haystack
        for (int i = 0; i <= n - m; ++i) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            // If we matched the entire needle, return the starting index
            if (j == m) {
                return i;
            }
        }
        
        return -1;
    }
};