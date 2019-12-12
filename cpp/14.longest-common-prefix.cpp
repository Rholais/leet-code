/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.38%)
 * Likes:    1748
 * Dislikes: 1547
 * Total Accepted:    585K
 * Total Submissions: 1.7M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }

        size_t u = UINT_MAX;
        for (const string &str : strs)
        {
            u = min(u, str.size());
        }
        unsigned numStrs = strs.size();
        string ret = "";
        for (unsigned i = 0; i != u; ++i)
        {
            const char c = strs[0][i];
            bool isSame = true;
            for (unsigned j = 1; j != numStrs; ++j)
            {
                if (strs[j][i] != c)
                {
                    isSame = false;
                    break;
                }
            }
            if (isSame)
            {
                ret += c;
            }
            else
            {
                break;
            }
        }
        return ret;
    }
};
// @lc code=end
