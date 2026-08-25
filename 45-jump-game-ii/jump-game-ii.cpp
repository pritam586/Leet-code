class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() -1; 
        int l = 0 ; 
        int r = 0;
        int jump =0;
        int far = 0;
       while(r<n){

        for(int i = l ; i<=r ; i++){
            far = max(far , i+nums[i]);
        }
        jump++;
        l = r+1;
        r = far;
       }
       return jump;
    }
};