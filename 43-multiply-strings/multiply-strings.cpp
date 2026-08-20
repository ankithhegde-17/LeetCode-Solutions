#include <string>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int n = num1.size();
        int m = num2.size();
        std::vector<int> pos(n + m, 0);
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + pos[p2];
                
                pos[p2] = sum % 10;
                pos[p1] += sum / 10;
            }
        }
        
        std::string result = "";
        for (int p : pos) {
            if (!(result.empty() && p == 0)) {
                result.push_back(p + '0');
            }
        }
        
        return result.empty() ? "0" : result;
    }
};