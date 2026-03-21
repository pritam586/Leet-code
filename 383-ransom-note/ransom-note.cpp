class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mp1;
        map<char, int> mp2;

        for(int i = 0; i < ransomNote.size(); i++) {
            mp1[ransomNote[i]]++;
        }

        for(int i = 0; i < magazine.size(); i++) {
            mp2[magazine[i]]++;
        }

        for(auto ch1 : mp1) {
            char ch = ch1.first;
            int count = ch1.second;

            if(mp2[ch] < count) {
                return false;
            }
        }

        return true;
    }
};