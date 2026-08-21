#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    long long findKthSmallest(std::vector<int>& coins, int k) {
        using ll = long long;
        int n = coins.size();
        ll l = 1, r = 25LL * k;
        
        auto gcd = [](ll a, ll b) {
            while (b) {
                a %= b;
                std::swap(a, b);
            }
            return a;
        };

        auto lcm = [&](ll a, ll b) {
            return (a / gcd(a, b)) * b;
        };

        auto check = [&](ll mx) {
            ll cnt = 0;
            for (int i = 1; i < (1 << n); ++i) {
                ll v = 1;
                int m = 0;
                for (int j = 0; j < n; ++j) {
                    if ((i >> j) & 1) {
                        m++;
                        v = lcm(v, coins[j]);
                        if (v > mx) break;
                    }
                }
                if (v <= mx) {
                    if (m & 1) {
                        cnt += mx / v;
                    } else {
                        cnt -= mx / v;
                    }
                }
            }
            return cnt >= k;
        };

        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};