#!/usr/bin/env python
#encoding utf-8

'''
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
'''

class Solution(object):
    def generateParenthesis(self, n):
        result = []
        if(n <= 0):
            return result
        self.helper(n, n, "", result)
        return result

    def helper(self, left, right, tmp, result):
        if(left < 0 or right < 0 or left > right):
            return
        if(left == 0 and right == 0):
            result.append(tmp)
        self.helper(left - 1, right, tmp + "(", result)
        self.helper(left, right - 1, tmp + ")", result)

if __name__ == '__main__':
    n = 3
    result = Solution().generateParenthesis(n)
    for item in result:
        print(item)