class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        
        int totalsum = 0;
        for(int i = 0; i < n; i++) totalsum += nums[i];

        
        vector<vector<long long>> leftSums(half + 1), rightSums(half + 1);

        for(int mask = 0; mask < (1 << half); mask++){
            long long sum = 0;
            int cnt = 0;
            for(int i = 0; i < half; i++){
                if(mask & (1 << i)){
                    sum += nums[i];
                    cnt++;
                }
            }
            leftSums[cnt].push_back(sum);
        }

        for(int mask = 0; mask < (1 << half); mask++){
            long long sum = 0;
            int cnt = 0;
            for(int i = 0; i < half; i++){
                if(mask & (1 << i)){
                    sum += nums[half + i];
                    cnt++;
                }
            }
            rightSums[cnt].push_back(sum);
        }

        for(int k = 0; k <= half; k++)
            sort(rightSums[k].begin(), rightSums[k].end());

        long long mini = 1e18;

        for(int k = 0; k <= half; k++){
            for(long long s1 : leftSums[k]){
                long long target = totalsum - 2 * s1;
            
                auto& rs = rightSums[half - k];

                auto it = lower_bound(rs.begin(), rs.end(), (target + 1) / 2);

                if(it != rs.end())
                    mini = min(mini, abs(target - 2 * (*it)));
                if(it != rs.begin()){
                    --it;
                    mini = min(mini, abs(target - 2 * (*it)));
                }
            }
        }

        return (int)mini;
    }
};