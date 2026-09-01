class Solution {
public:
    void fun(string &digits,int n,int indx,string &temp,vector<string>&res,unordered_map<char,string>&f){
        if(indx==n){
            res.push_back(temp);
            return;
        }
        // choice;
        string choice = f[digits[indx]];
        for(int i=0; i<choice.size(); i++){
            temp.push_back(choice[i]);
            fun(digits, n , indx+1,temp,res,f);
            temp.pop_back();
        }
        return ;
      
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>f;
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";

        int n = digits.size();

        string temp = "";
        vector<string>res;

        fun(digits,n,0,temp,res,f);

        return res;

    }
};