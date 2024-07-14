#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        stk.push({}); // Initialize with an empty map
        
        int i = 0, n = formula.length();
        
        while (i < n) {
            if (formula[i] == '(') {
                // Push an empty map for a new group
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                // Pop the top map when encountering a closing parenthesis
                unordered_map<string, int> top = stk.top();
                stk.pop();
                i++;
                // Find the multiplier after the parenthesis
                int start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int multiplier = start < i ? stoi(formula.substr(start, i - start)) : 1;
                // Multiply all elements in the popped map by the multiplier
                for (auto& kv : top) {
                    stk.top()[kv.first] += kv.second * multiplier;
                }
            } else {
                // Parse the element name
                int start = i++;
                while (i < n && islower(formula[i])) {
                    i++;
                }
                string element = formula.substr(start, i - start);
                // Parse the element count
                start = i;
                while (i < n && isdigit(formula[i])) {
                    i++;
                }
                int count = start < i ? stoi(formula.substr(start, i - start)) : 1;
                // Add the element and its count to the current map
                stk.top()[element] += count;
            }
        }
        
        // Collect and sort all elements in the final map
        unordered_map<string, int> result = stk.top();
        vector<string> elements;
        for (auto& kv : result) {
            elements.push_back(kv.first);
        }
        sort(elements.begin(), elements.end());
        
        // Build the result string
        string res;
        for (const auto& element : elements) {
            res += element;
            if (result[element] > 1) {
                res += to_string(result[element]);
            }
        }
        
        return res;
    }
};

// Example usage:
int main() {
    Solution solution;
    string formula = "H2O";
    cout << solution.countOfAtoms(formula) << endl; // Output: H2O

    formula = "Mg(OH)2";
    cout << solution.countOfAtoms(formula) << endl; // Output: H2MgO2

    formula = "K4(ON(SO3)2)2";
    cout << solution.countOfAtoms(formula) << endl; // Output: K4N2O14S4

    return 0;
}
