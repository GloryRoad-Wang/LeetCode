#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
    Problem:
        Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
        For example, given n = 3, a solution set is:
        [
          "((()))",
          "(()())",
          "(())()",
          "()(())",
          "()()()"
        ]
*/

class Solution {
public:
    vector<string> generate_parenthesis(int n) {
        vector<string> result;
        if(n <= 0)
            return result;
        helper(n, n, "", result);
        return result;
    }
private:
    void helper(int left, int right, string tmp, vector<string>& res) {
        if(left < 0 || right < 0 || left > right) return;
        if(left == 0 && right == 0) {
            res.push_back(tmp);
            return;
        }
        helper(left-1, right, tmp+"(", res);
        helper(left, right-1, tmp+")", res);
    }
};

int main() {
    int n = 3;
    vector<string> parenthesis = Solution().generate_parenthesis(n);
    for(int i = 0; i < parenthesis.size(); i++) {
        cout << parenthesis[i] << endl;
    }
}