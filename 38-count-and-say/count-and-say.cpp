class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        string temp="11";
        string temp2;
        for(int i=3;i<=n;i++){
            temp2=temp;
            temp2+='#'; // to mark the end of string
            temp="";
            int cnt=1;
            for(int j=1;j<temp2.length();j++){
                if(temp2[j-1]==temp2[j])
                    cnt++;
                else{
                    temp+=to_string(cnt);
                    temp+=temp2[j-1];
                    cnt=1;
                }
            }
        }
        return temp;
    }
};