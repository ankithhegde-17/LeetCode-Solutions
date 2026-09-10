#include <algorithm>

class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        long long p10[7] = {
            1, 
            1000, 
            1000000LL, 
            1000000000LL, 
            1000000000000LL, 
            1000000000000000LL, 
            1000000000000000000LL
        };
        
        for (int k = 1; k <= 5; ++k) {
            if (p10[k] > n) break;
            long long l = p10[k];
            long long r = std::min(n, p10[k + 1] - 1);
            total_commas += (long long)k * (r - l + 1);
        }
        
        return total_commas;
    }
};