/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (26.37%)
 * Total Accepted:    466.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        unsigned mb = 0;
        unsigned ms = 0;
        unsigned ns = s.size();
        for (unsigned i = 0; i != ns; ++i)
        {
            int begin = static_cast<int>(i) - 1;
            unsigned end = i + 1;
            for (; begin >= 0 && end < ns && s[begin] == s[end]; --begin, ++end)
            {
            }
            unsigned size = static_cast<int>(end) - begin - 1;
            if (size > ms)
            {
                ms = size;
                mb = begin + 1;
            }
            if (i == ns - 1 || s[i] != s[i + 1])
            {
                continue;
            }
            begin = static_cast<int>(i) - 1;
            end = i + 2;
            for (; begin >= 0 && end < ns && s[begin] == s[end]; --begin, ++end)
            {
            }
            size = static_cast<int>(end) - begin - 1;
            if (size > ms)
            {
                ms = size;
                mb = begin + 1;
            }
        }
        return s.substr(mb, ms);
    }
};
