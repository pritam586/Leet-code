class Solution {
public:
    int ladderLength(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());

        if(st.find(endGene) == st.end()) return 0; 

        unordered_set<string> visited;
        queue<string> que;

        que.push(startGene);
        visited.insert(startGene);

        int level = 1; 

        while(!que.empty()){
            int n = que.size();

            while(n--){
                string curr = que.front();
                que.pop();

                if(curr == endGene){
                    return level;
                }

                for(char ch : {'a','b','c','d','e','f','g','h','i','j','k','l','m',
                               'n','o','p','q','r','s','t','u','v','w','x','y','z'}){

                    for(int i = 0; i < curr.length(); i++){
                        string neg = curr;

                        if(neg[i] == ch) continue; 

                        neg[i] = ch;

                        if(visited.find(neg) == visited.end() && st.find(neg) != st.end()){
                            visited.insert(neg);
                            que.push(neg);
                        }
                    }
                }
            }

            level++;
        }

        return 0;
    }
};