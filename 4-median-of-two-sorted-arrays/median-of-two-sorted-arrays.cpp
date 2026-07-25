class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        
        int reqIndex = total / 2; // Median tak pahunchne ki position
        
        int i = 0, j = 0;
        int count = 0;
        int prev = 0, curr = 0;

        // Sirf tab tak chalo jab tak required index tak na pahunch jaayein
        while (count <= reqIndex) {
            prev = curr; // Last second element track karo
            
            if (i < n && (j >= m || nums1[i] < nums2[j])) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }
            count++;
        }

        // Even length me do middle elements ka average, Odd me single middle element
        if (total % 2 == 0) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
    }
};