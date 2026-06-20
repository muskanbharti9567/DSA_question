class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize two pointers at opposite ends of the array
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;
        
        while (left < right) {
            // The water level is limited by the shorter of the two walls
            int current_height = min(height[left], height[right]);
            int current_width = right - left;
            
            // Calculate current area and update max_water if it's larger
            int current_area = current_height * current_width;
            max_water = max(max_water, current_area);
            
            // Move the pointer pointing to the shorter wall inward.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};