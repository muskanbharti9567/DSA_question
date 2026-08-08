class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end()); // 1. Must sort first
        int n = nums.size();
        int min_diff = INT_MAX;
        int res = 0;

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            // 2. Loop while pointers don't cross
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);

                // 3. Update closest sum if a smaller difference is found
                if (diff < min_diff) {
                    min_diff = diff;
                    res = sum;
                }

                if (sum == target) {
                    return sum;
                } 
                else if (sum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        return res;
    }
};