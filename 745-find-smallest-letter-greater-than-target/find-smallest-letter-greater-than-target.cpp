class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int idx = upper_bound(letters.begin(),letters.end(),target)-begin(letters);
        if(idx==n){
            return letters[0];
        }
        return letters[idx];
        
    }
};