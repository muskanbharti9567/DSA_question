class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;
        for(int i = max(101 , num1); i <= num2; ++i){
            int temp = i, a, b;
            a = temp % 10; temp /= 10;
            b = temp % 10; temp /= 10;
            while(temp){
                int c = temp % 10;
                if(max(a , c) < b || b < min(a , c)) ++res;
                a = b; b = c;
                temp /= 10;
            }
        }
        return res;
    }
};