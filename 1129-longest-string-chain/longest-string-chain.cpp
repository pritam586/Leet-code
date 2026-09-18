class Solution {
public:
   int longestStrChain(std::vector<std::string>& words) {
        // Sort words by their length in ascending order
        sort(words.begin(), words.end(), [](const std::string& a, const string& b) {
            return a.length() < b.length();
        });

       unordered_map<string, int> dp;
        int maxLength = 1;

        for (const string& word : words) {
            int currentMax = 1;
            int len = word.length();

            // Try removing each character to find a predecessor
            for (int i = 0; i < len; ++i) {
               string predecessor = word.substr(0, i) + word.substr(i + 1);
                
                if (dp.find(predecessor) != dp.end()) {
                    currentMax = max(currentMax, dp[predecessor] + 1);
                }
            }

            dp[word] = currentMax;
            maxLength = max(maxLength, currentMax);
        }

        return maxLength;
    }
};