class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        // if indx is start with odd and end with even (3,4) => low = mid+1;
        // if indx is start with even and end with odd  =>  high = mid-1;
        // agr even indx pr hai to mid-1 check kro 
        // agr odd indx pr hai to mid+1 check kro

        while(low<=high){
            int mid = (low+high)/2;
            if (n == 1) return nums[0];
            if (nums[0] != nums[1]) return nums[0];
            if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

            
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if(((mid%2)==0 && nums[mid]==nums[mid+1])
            ||((mid%2)==1 && nums[mid]==nums[mid-1])){
                low = mid+1;
            }
            else{
               high = mid-1;
            }
            
        }
        return -1;  
    }
};