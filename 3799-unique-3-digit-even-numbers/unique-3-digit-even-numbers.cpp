#include <vector>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        std::vector<int> count(10, 0);
        for (int d : digits) {
            count[d]++;
        }
        
        int ans = 0;
        for (int i = 100; i <= 998; i += 2) {
            int h = i / 100;
            int t = (i / 10) % 10;
            int o = i % 10;
            
            std::vector<int> tempCount(10, 0);
            tempCount[h]++;
            tempCount[t]++;
            tempCount[o]++;
            
            bool possible = true;
            for (int d = 0; d < 10; ++d) {
                if (tempCount[d] > count[d]) {
                    possible = false;
                    break;
                }
            }
            if (possible) {
                ans++;
            }
        }
        return ans;
    }
};