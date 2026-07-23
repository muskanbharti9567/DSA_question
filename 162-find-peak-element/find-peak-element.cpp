class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Peak exists on the right side
                low = mid + 1;
            } 
            else {
                // mid itself could be a peak
                // so don't remove mid
                high = mid;
            }
        }

        return low;
    }
};