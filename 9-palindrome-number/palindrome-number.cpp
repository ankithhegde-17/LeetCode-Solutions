class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and non-zero numbers ending in 0 are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // Even length: x == revertedNumber
        // Odd length: x == revertedNumber / 10
        return x == revertedNumber || x == revertedNumber / 10;
    }
};