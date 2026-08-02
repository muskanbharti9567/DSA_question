class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>a; //positive
        vector<int>b; //negative

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=0){
                a.push_back(nums[i]);
            }
            else{
                b.push_back(nums[i]);
            }
        }

        // if array is positive
        if(b.size()==0){
            for(int i=0; i<a.size(); i++){
                a[i] = a[i]*a[i];
            }
            return a;
        }

        // if array is negative
        if(a.size()==0){
            for(int i=0; i<b.size(); i++){
                b[i]= b[i]*b[i];
            }
            reverse(b.begin(),b.end());
            return b;
        }

        // if array is positive + negative
        int n = a.size();
        int m = b.size();
        vector<int>res;
        int i=0;
        int j=0;

        if(a.size()!=0 && b.size()!=0){

            for(int i=0; i<n; i++){
                a[i]=a[i]*a[i];
            }
            for(int j=0; j<m; j++){
                b[j]=b[j]*b[j];
            }
            reverse(b.begin(),b.end());

            while(i<n && j<m){
                if(a[i]<b[j]){
                    res.push_back(a[i]);
                    i++;
                }
                else{
                    res.push_back(b[j]);
                    j++;
                }
            }
            while(i<n){
                res.push_back(a[i]);
                i++;
            }
            while(j<m){
                res.push_back(b[j]);
                j++;
            }
        }
        return res;
        
    }
};