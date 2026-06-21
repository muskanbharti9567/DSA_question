class Solution {
public: 
    void rec(int i, int t, vector<int>v, vector<vector<int>>&ans, vector<int>nums){
        int n=nums.size();
        if(t==0){ 
            ans.push_back(v);
            return;
        }
        for(int j=i;j<n;j++){
            if(j>i && nums[j]==nums[j-1])continue;
            if(nums[j]>t) break;

            v.push_back(nums[j]);
            rec(j+1,t-nums[j],v,ans,nums);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        rec(0,target,v,ans,candidates);
        return ans;
    }
};