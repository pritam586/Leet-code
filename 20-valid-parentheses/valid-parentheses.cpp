class Solution {
public:
    bool isValid(string s) {
      
        stack<char> st;
        for(char x:s){
            if(x == '(' || x=='{' || x=='['){
                st.push(x);
            }
            if(x == ')'){
                if(st.empty()) return false;
                if(st.top()!='(') return false;
                st.pop();
            }else if(x=='}'){
                if(st.empty()) return false;
                if(st.top()!='{') return false;
                st.pop();
            }else if(x==']'){
                if(st.empty()) return false;
                if(st.top()!='[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};