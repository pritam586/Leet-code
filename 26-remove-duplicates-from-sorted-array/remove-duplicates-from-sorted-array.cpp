class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique = nums[0];
        int count = 1;
        int j = 1;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]!=unique){
                count++;
                nums[j] = nums[i];
                unique = nums[i];
                j++;
            }
        }

        return count;
    }
};