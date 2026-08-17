#include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Arrays representing values and their corresponding Roman numeral symbols
        std::vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::vector<std::string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        std::string result = "";
        
        // Greedily subtract values from the largest to the smallest
        for (size_t i = 0; i < values.size(); ++i) {
            while (num >= values[i]) {
                num -= values[i];
                result += symbols[i];
            }
        }
        
        return result;
    }
};