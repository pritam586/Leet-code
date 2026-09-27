class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_one = 0;
        int count = 0;
        for(int i =0 ; i<nums.size() ; i++){
            if(nums[i]==1){
                count++;
                max_one = max(max_one , count);
            }else{
                count = 0;
            }
        }

        return max_one;
        
    }
};