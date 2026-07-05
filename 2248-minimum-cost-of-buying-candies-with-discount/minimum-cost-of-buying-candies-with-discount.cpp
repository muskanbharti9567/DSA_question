class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        sort(cost.rbegin(), cost.rend());

        int start = 0;
        int end = start + 1;

        while (start < cost.size()) {
            ans += cost[start];

            if (end < cost.size()) {
                ans += cost[end];
            }

            start += 3;
            end += 3;
        }

        return ans;
    }
};