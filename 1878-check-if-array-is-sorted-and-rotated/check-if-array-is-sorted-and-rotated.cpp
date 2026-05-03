class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(); 
        int count = 0;      

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > nums[(i+1) % n]){
                count++;  

            //     int curr = nums[i];
            //     int j = nums[(i+1) % n];
            //     int idx = i;

            //     for(int k = idx ; k >= 0 ; k--){
            //         if(nums[k] < j){
            //             return false;
            //         }
            //     }

            //     for(int k = idx ; k < n ; k++){
            //         if(nums[k] > curr){
            //             return false;
            //         }
            //     }
            // }
            }
        }
        if(count > 1) return false;

        return true;
    }
};