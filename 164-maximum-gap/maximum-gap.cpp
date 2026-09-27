class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        if (minVal == maxVal)
            return 0;

        
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));

        
        int bucketCount = (maxVal - minVal) / bucketSize + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);

       
        for (int num : nums) {
            int index = (num - minVal) / bucketSize;

            bucketMin[index] = min(bucketMin[index], num);
            bucketMax[index] = max(bucketMax[index], num);
        }

        int maxGap = 0;
        int previousMax = minVal;

        
        for (int i = 0; i < bucketCount; i++) {

          
            if (bucketMin[i] == INT_MAX)
                continue;

            maxGap = max(maxGap, bucketMin[i] - previousMax);

            previousMax = bucketMax[i];
        }

        return maxGap;
    }
};