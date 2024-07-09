#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int available_at = 0;
        double total_wait = 0;
        for (auto& customer : customers) {
            int arrival = customer[0], t = customer[1];
            available_at = max(available_at, arrival) + t;
            total_wait += available_at - arrival;
        }
        return total_wait / customers.size();
    }
};

int main() {
    Solution solution;
    vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};

    double result = solution.averageWaitingTime(customers);
    cout << "The average waiting time is: " << result << endl;

    return 0;
}
