/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * https://leetcode.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (25.93%)
 * Likes:    3277
 * Dislikes: 606
 * Total Accepted:    360.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '"aa"\n"a"'
 *
 * Given an input string (s) and a pattern (p), implement regular expression
 * matching with support for '.' and '*'.
 * 
 * 
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * 
 * 
 * The matching should cover the entire input string (not partial).
 * 
 * Note:
 * 
 * 
 * s could be empty and contains only lowercase letters a-z.
 * p could be empty and contains only lowercase letters a-z, and characters
 * like . or *.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "aa"
 * p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "ab"
 * p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input:
 * s = "aab"
 * p = "c*a*b"
 * Output: true
 * Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
 * it matches "aab".
 * 
 * 
 * Example 5:
 * 
 * 
 * Input:
 * s = "mississippi"
 * p = "mis*is*p*."
 * Output: false
 * 
 * 
 */

// @lc code=start

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    static bool isMatch(const string &s, const string &p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (unsigned j = 0; j != p.size(); ++j)
        {
            if (p[j] == '*' && dp[0][j - 1])
            {
                dp[0][j + 1] = true;
            }
        }
        for (unsigned i = 0; i != s.size(); ++i)
        {
            for (unsigned j = 0; j != p.size(); ++j)
            {
                if (s[i] == p[j] || p[j] == '.')
                {
                    dp[i + 1][j + 1] = dp[i][j];
                }
                else if (p[j] == '*')
                {
                    if (s[i] != p[j - 1] && p[j - 1] != '.')
                    {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    }
                    else
                    {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i + 1][j] || dp[i][j + 1];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end
