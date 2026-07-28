class Solution {
public:
    int max_array(vector<int>& piles){
        int max = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            if(piles[i]>max){
                max = piles[i];
            }
        }
        return max;
    }
    long long Hours(vector<int>& piles,  int mid){
        long long h = 0;
        for(int i=0; i<piles.size(); i++){
            h = h + piles[i]/mid;

            if(piles[i] % mid!=0){
                h++;
            }
        }
        return h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = max_array(piles);
        int res = -1;

        while(low<=high){
            int mid = low + (high-low)/2;
            long long hour = Hours(piles, mid);
            if(hour > h){
                low = mid+1;
            } 
            else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
        
    }
};