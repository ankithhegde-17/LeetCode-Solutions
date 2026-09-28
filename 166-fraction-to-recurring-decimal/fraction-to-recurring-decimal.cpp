class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;

        long long num = numerator;
        long long den = denominator;

        if ((num < 0) ^ (den < 0)) res += '-';

        num = llabs(num);
        den = llabs(den);

        res += to_string(num / den);

        long long rem = num % den;

        if (rem == 0) return res;

        res += '.';

        unordered_map<long long, int> mp;

        while (rem != 0) {
            if (mp.count(rem)) {
                res.insert(mp[rem], "(");
                res += ')';
                break;
            }

            mp[rem] = res.size();

            rem *= 10;
            res += to_string(rem / den);
            rem %= den;
        }

        return res;
    }
};