class Solution {
public:
    string binary(int n){
        string ans = "";
        while(n > 0){
            int m = n % 2;
            ans.push_back(m + '0'); 
            n /= 2;                
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int minBitFlips(int start, int goal) {
        string st  = binary(start);
        string ed = binary(goal);

        int count = 0;

        int n = max(st.size(), ed.size());

        while(st.size() < n) st = "0" + st;
        while(ed.size() < n) ed = "0" + ed;

        for(int i = 0; i < n; i++){
            if(st[i] != ed[i]){
                count++;
            }
        }
        return count;
    }
};