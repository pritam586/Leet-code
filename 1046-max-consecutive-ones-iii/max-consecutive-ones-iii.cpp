class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans  = 0;
        int zero = 0;

        
        while(right < nums.size()){
            if(nums[right] == 1){ 
                ans = max(ans , right - left + 1);   
            }else{
                if(zero >= k){
                    while(nums[left] == 1){  
                        left++;
                    }
                    left++;
                }else{
                    zero++; 
                }
                ans = max(ans , right - left + 1); 
            }

            right++; 
        }

        return ans;
    }
};
