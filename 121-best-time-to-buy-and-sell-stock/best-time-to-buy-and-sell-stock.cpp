class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX, max_prof = 0;
        for (int p : prices) {
            min_price = min(min_price, p);
            max_prof = max(max_prof, p - min_price);
        }
        return max_prof;
    }
};