class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;

        for (int i = 0; i < bills.size(); i++) {

            if (bills[i] == 5) {
                five++;
            }

            else if (bills[i] == 10) {

                // Need one $5
                if (five < 1)
                    return false;

                five--;
                ten++;
            }

            else { 

               
                if (ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                }

        
                else if (five >= 3) {
                    five -= 3;
                }

                else {
                    return false;
                }
            }
        }

        return true;
    }
};