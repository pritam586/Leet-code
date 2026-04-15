class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
          unordered_set<string> st(bank.begin(), bank.end());
          unordered_set<string> visited;
          queue<string> que;

          que.push(startGene);
          visited.insert(startGene);
          int level = 0;

          while(!que.empty()){
            int n = que.size();
            while(n--){
                string curr = que.front();
                que.pop();
                if(curr==endGene){
                    return level;
                }

                for(char ch:"ACGT"){
                    for(int i = 0 ; i<curr.length() ; i++){
                        string neg = curr;
                        neg[i] = ch;

                        if(visited.find(neg)==visited.end() && st.find(neg) != st.end()){
                            visited.insert(neg);
                            que.push(neg);
                        }
                    }
                }
            }
            level++;
          }

          return -1;
    }
};