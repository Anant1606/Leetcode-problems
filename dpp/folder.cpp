#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int step = 0;
        for (const auto& log : logs) {
            if (log == "../") {
                if (step > 0) step--;
            } else if (log != "./") {
                step++;
            }
        }
        return step;
    }
};

int main() {
    vector<string> logs = {"d1/", "d2/", "../", "d21/", "./"};
    Solution solution;
    cout << solution.minOperations(logs) << endl;  // Output: 2
    return 0;
}
