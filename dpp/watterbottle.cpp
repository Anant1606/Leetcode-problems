#include <iostream>

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;

        while (numBottles >= numExchange) {
            int newBottles = numBottles / numExchange;
            int remainingBottles = numBottles % numExchange;
            ans += newBottles;
            numBottles = newBottles + remainingBottles;
        }

        return ans;
    }
};

int main() {
    Solution solution;
    int numBottles = 9;
    int numExchange = 3;

    int result = solution.numWaterBottles(numBottles, numExchange);
    std::cout << "Total number of bottles you can drink: " << result << std::endl;

    return 0;
}
