class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.size();

        stack<char> st;  

        st.push(num[0]);

        for(int i = 1 ; i < n ; i++){

            while(st.size() > 0 && k > 0 && num[i] < st.top()){
                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        while(k > 0 && st.size() > 0){
            st.pop();
            k--;
        }

        if(st.empty()) return "0";

        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;

        while(i < ans.size() && ans[i] == '0'){
            i++;
        }

        ans = ans.substr(i);

        if(ans == "") return "0";

        return ans;
    }
};