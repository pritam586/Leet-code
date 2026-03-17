class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int count = 0;
        while(ans!=0){
            int m = ans%2;
            if(m==1){
                count++;
            }
            ans/=2;
        }
        return count;
    }
};