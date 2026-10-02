class Solution {

public:

    bool possible(int x, int mid) {
        if (1LL * mid * mid <= x)
            return true;

        return false;
    }

    int mySqrt(int x) {
        int low = 1;
        int high = x;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (possible(x, mid)) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return high;
    }
};