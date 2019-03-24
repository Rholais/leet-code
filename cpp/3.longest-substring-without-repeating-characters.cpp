/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (26.11%)
 * Total Accepted:    741.6K
 * Total Submissions: 2.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string, find the length of the longest substring without repeating
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abcabcbb"
 * Output: 3 
 * Explanation: The answer is "abc", with the length of 3. 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3. 
 * ⁠            Note that the answer must be a substring, "pwke" is a
 * subsequence and not a substring.
 * 
 * 
 * 
 * 
 * 
 */
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        unsigned ret = 0;
        unsigned start = 0;
        vector<int> dict(256, -1);
        for (unsigned i = 0; i != s.size(); ++i)
        {
            if (dict[s[i]] >= static_cast<int>(start))
            {
                ret = max(ret, i - start);
                start = dict[s[i]] + 1;
            }
            dict[s[i]] = i;
        }
        return max(ret, static_cast<unsigned>(s.size()) - start);
    }
};
