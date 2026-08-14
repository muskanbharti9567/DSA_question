class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int low = 0;
        int res = 0;

        unordered_map<char,int>freq;

        for(int high=0; high<n; high++){
            freq[s[high]]++;

            int len = high-low+1;

            while(freq.size()<len){
                freq[s[low]]--;

                if(freq[s[low]]==0){
                    freq.erase(s[low]);
                }
                low++;
                len = high-low+1;
            }
            len = high-low+1;
            res = max(len,res);

        }
        return res;
        
    }
};