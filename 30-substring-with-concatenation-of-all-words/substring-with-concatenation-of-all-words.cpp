class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int> ans;

        int wordLen = words[0].length();
        int wordSize = wordLen * words.size();

         unordered_map<string, int> have;
        for(string word : words){
            have[word]++;
        }

        if(wordSize>s.length()){
            return ans;
        }

        for(int l = 0 ; l <= s.size() - wordSize ; l++){

            string temp = s.substr(l, wordSize);   
            unordered_map<string , int> need;

           
            for(int j = 0 ; j < wordSize ; j += wordLen){
                string part = temp.substr(j, wordLen);
                need[part]++;
            }

            if(need == have){
                ans.push_back(l);
            }
        }

        return ans;
    }
};
