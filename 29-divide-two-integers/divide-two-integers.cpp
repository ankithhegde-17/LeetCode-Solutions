#include <climits>
#include <cstdlib>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the special case for 32-bit signed integer overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN;
        }
        
        // Determine the sign of the final quotient
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // Use long long to prevent overflow when taking the absolute value of INT_MIN
        long long dvd = std::labs(dividend);
        long long dvs = std::labs(divisor);
        
        long long quotient = 0;
        
        // Bitwise division using exponential search (multiples of powers of 2)
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;
            
            // Find the largest shifted divisor that fits into the remaining dividend
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            
            dvd -= temp;
            quotient += multiple;
        }
        
        return negative ? -quotient : quotient;
    }
};