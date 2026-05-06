class Solution {
public:
    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0 ; i < piles.size() ; i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calTotalHr(vector<int>& piles, int k){
        long long total = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            total += (piles[i] + k - 1) / k;
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = findMax(piles);

        while(low <= high){
            int mid = low + (high - low) / 2;

            long long totalHr = calTotalHr(piles, mid);

            if(totalHr <= h){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};