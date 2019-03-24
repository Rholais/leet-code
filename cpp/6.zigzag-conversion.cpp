/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (30.42%)
 * Total Accepted:    283.6K
 * Total Submissions: 929.9K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */
class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        vector<string> ex(numRows, "");
        for (unsigned i = 0; i != s.size(); ++i)
        {
            ex[numRows - abs((static_cast<int>(i) % ((numRows - 1) * 2)) - numRows + 1) - 1] += s[i];
        }
        string ret = "";
        for (const string &e : ex)
        {
            ret += e;
        }
        return ret;
    }
};
