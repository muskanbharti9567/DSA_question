class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;

        for(auto & ch : operations){
            if(ch!="C"&& ch!="D"&& ch!="+"){
                s.push(stoi(ch));
            }
            else if(ch=="C"){
                s.pop();
            }
            else if(ch=="D"){
                s.push(2*s.top());
            }  
            else{
                int first = s.top();
                s.pop();
                int sec = s.top();
                s.push(first);
                s.push(first+sec);

            }  
        }
        int ans = 0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();

        }
        return ans;
        
    }
};