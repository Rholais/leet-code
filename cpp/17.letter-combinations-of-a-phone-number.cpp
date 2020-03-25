/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (43.77%)
 * Likes:    2793
 * Dislikes: 349
 * Total Accepted:    479.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return {};
        }

        const vector<vector<char>> vvc = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        const unsigned numDigits = digits.size();
        vector<unsigned> vu(numDigits, 0);
        vector<string> ret;
        while (true)
        {
            string s = "";
            for (unsigned i = 0; i != numDigits; ++i)
            {
                s += vvc[digits[i] - '2'][vu[i]];
            }
            ret.push_back(s);

            bool isFinished = true;
            for (unsigned i = 0; i != numDigits; ++i)
            {
                if (vu[i] + 1 != vvc[digits[i] - '2'].size())
                {
                    isFinished = false;
                    break;
                }
            }
            if (isFinished)
            {
                return ret;
            }

            for (unsigned i = 0; i != numDigits; ++i)
            {
                if (vu[i] + 1 == vvc[digits[i] - '2'].size())
                {
                    vu[i] = 0;
                }
                else
                {
                    ++vu[i];
                    break;
                }
            }
        }
    }
};
// @lc code=end
