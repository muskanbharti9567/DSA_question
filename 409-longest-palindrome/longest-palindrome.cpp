class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        int res = 0;
        bool odd = false;
        for(auto i : mp){
            int val = i.second;
            if(val%2==0){
                res+=val;
            }
            else{
                odd=true;
                res+=val-1;
            }
        }
        if(odd){
            res+=1;
        }
        return res;
        
    }
};