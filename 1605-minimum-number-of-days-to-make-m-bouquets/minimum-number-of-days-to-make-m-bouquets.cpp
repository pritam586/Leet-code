class Solution {
public:
    bool possible(vector<int>& bloomDay, int mid, int m, int k){
        int noB = 0;
        int count = 0;

        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                count++;
            } else {
                noB += (count / k);
                count = 0;
            }
        }

        noB += (count / k); 
        return noB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // 🔥 Edge case
        if((long long)m * k > bloomDay.size()) return -1;

        int low = INT_MAX;
        int high = INT_MIN;

        for(int i = 0 ; i < bloomDay.size() ; i++){
            low = min(low , bloomDay[i]);
            high = max(high , bloomDay[i]);
        }

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(possible(bloomDay, mid, m, k)){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};