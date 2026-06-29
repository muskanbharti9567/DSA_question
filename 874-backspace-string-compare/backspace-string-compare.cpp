class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;

        for(auto& ch : s){
            if(ch!='#'){
                s1.push(ch);
            }
            else if(!s1.empty()){
                s1.pop();
            }    
        }
        for(auto& ch : t){
            if(ch!='#'){
                s2.push(ch);
            }
            else if(!s2.empty()){
                s2.pop();
            }        
        }
        return s1==s2;
        
    }
};