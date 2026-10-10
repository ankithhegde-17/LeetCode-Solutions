class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long total_k = (long long)k1 + k2;
        long long initial_sum = 0;

        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            initial_sum += diff[i];
        }

        if (initial_sum <= total_k) {
            return 0;
        }

        unordered_map<long long, long long> counts;
        long long max_diff = 0;
        for (int i = 0; i < n; ++i) {
            counts[diff[i]]++;
            max_diff = max(max_diff, diff[i]);
        }

        priority_queue<long long> pq;
        for (auto& pair : counts) {
            pq.push(pair.first);
        }

        while (total_k > 0 && !pq.empty()) {
            long long curr = pq.top();
            pq.pop();

            if (curr == 0) break;

            long long count = counts[curr];
            long long next_val = pq.empty() ? 0 : pq.top();
            long long diff_val = curr - next_val;
            long long operations_needed = diff_val * count;

            if (total_k >= operations_needed) {
                total_k -= operations_needed;
                counts[next_val] += count;
                counts.erase(curr);
            } else {
                long long decrease = total_k / count;
                long long remainder = total_k % count;
                
                counts[curr] -= count;
                counts[curr - decrease] += count - remainder;
                counts[curr - decrease - 1] += remainder;
                
                if (counts[curr] == 0) counts.erase(curr);
                pq.push(curr - decrease);
                if (curr - decrease - 1 >= 0) {
                    pq.push(curr - decrease - 1);
                }
                total_k = 0;
            }
        }

        long long result = 0;
        for (auto& pair : counts) {
            result += pair.first * pair.first * pair.second;
        }

        return result;
    }
};