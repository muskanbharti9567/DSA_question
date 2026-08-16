class Solution {
public:
    int characterReplacement(string s, int k) {
        // sliding window
        unordered_map<char,int>freq;
        int low = 0;
        int max_freq = 0;
        int ans = 0;
        for(int high=0; high<s.length(); high++){
            freq[s[high]]++;

            int len = high-low+1;
            max_freq = max(max_freq,freq[s[high]]);
            int dist = len-max_freq;

            if(dist>k){
                // hume bss k replacement se jyada ni krna 
                freq[s[low]]--;
                low++;
                len = high-low+1;
            }
            ans = max(ans,len);
        }
        return ans;
        
    }
};