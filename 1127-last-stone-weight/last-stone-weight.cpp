class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        // make max heap;
        priority_queue<int>pq;
        for(auto it : stones){
            pq.push(it);
        }

        while(pq.size()>1){
            int Y = pq.top();
            pq.pop();
            int X = pq.top();
            pq.pop();
            
            if(X==Y){
                continue;
            }
            else{
                Y=Y-X; 
                pq.push(Y); 
            }
        }
        if(!pq.empty()) return pq.top();
        else return 0;
    }
};