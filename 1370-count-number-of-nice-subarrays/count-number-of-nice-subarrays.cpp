class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int ans = 0;
        int left = 0;
        int oddCount = 0;
        int temp = 0;

        for(int r = 0; r < nums.size(); r++) {

            if(nums[r] % 2 == 1) {
                oddCount++;
                temp = 0;
            }

            while(oddCount == k) {

                temp++;

                if(nums[left] % 2 == 1) {
                    oddCount--;
                }

                left++;
            }

            ans += temp;
        }

        return ans;
    }
};