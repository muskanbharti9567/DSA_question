class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<pair<int,int>> freq;

        for (int i = 0; i < nums.size(); i++) {

            bool alreadyCounted = false;

            // Check whether nums[i] appeared before
            for (int j = 0; j < i; j++) {
                if (nums[j] == nums[i]) {
                    alreadyCounted = true;
                    break;
                }
            }

            if (alreadyCounted)
                continue;

            // Count frequency of nums[i]
            int count = 0;

            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }

            freq.push_back({count, nums[i]});
        }

        sort(freq.rbegin(), freq.rend());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].second);
        }

        return ans;
    }
};