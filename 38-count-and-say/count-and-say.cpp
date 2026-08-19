#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n == 1) return "1";

        std::string current = "1";

        // Iteratively build each term up to n
        for (int i = 2; i <= n; ++i) {
            std::string next = "";
            int len = current.length();
            int j = 0;

            while (j < len) {
                int count = 1;
                // Count consecutive identical characters
                while (j + 1 < len && current[j] == current[j + 1]) {
                    count++;
                    j++;
                }
                // Append the count followed by the character to the next sequence
                next += std::to_string(count) + current[j];
                j++;
            }
            current = next;
        }

        return current;
    }
};