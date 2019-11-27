/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (47.67%)
 * Likes:    4261
 * Dislikes: 490
 * Total Accepted:    489K
 * Total Submissions: 1M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 */

// @lc code=start

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    static int maxArea(vector<int> &height)
    {
        unsigned l = 0;
        unsigned nl = l;
        unsigned nnl = l;
        int r = height.size() - 1;
        int nr = r;
        int nnr = r;
        for (; nnl != height.size() && height[nnl] <= height[l]; ++nnl)
            ;
        for (; nnr != -1 && height[nnr] <= height[r]; --nnr)
            ;
        while (nnl != height.size() || nnr != -1)
        {
            if (nnl == height.size())
            {
                nr = nnr;
            }
            else if (nnr == -1)
            {
                nl = nnl;
            }
            else
            {
                if (height[nl] < height[nr])
                {
                    nl = nnl;
                }
                else if (height[nl] > height[nr])
                {
                    nr = nnr;
                }
                else
                {
                    nl = nnl;
                    nr = nnr;
                }
            }
            if (nnl == nl)
            {
                for (; nnl != height.size() && height[nnl] <= height[nl]; ++nnl)
                    ;
            }
            if (nnr == nr)
            {
                for (; nnr != -1 && height[nnr] <= height[nr]; --nnr)
                    ;
            }
            if (min(height[nl], height[nr]) * (nr - nl) >= min(height[l], height[r]) * (r - l))
            {
                l = nl;
                r = nr;
            }
        }
        return min(height[l], height[r]) * (r - l);
    }
};
// @lc code=end

int main()
{
    vector<int> height = {76,
                          155,
                          15,
                          188,
                          180,
                          154,
                          84,
                          34,
                          187,
                          142,
                          22,
                          5,
                          27,
                          183,
                          111,
                          128,
                          50,
                          58,
                          2,
                          112,
                          179,
                          2,
                          100,
                          111,
                          115,
                          76,
                          134,
                          120,
                          118,
                          103,
                          31,
                          146,
                          58,
                          198,
                          134,
                          38,
                          104,
                          170,
                          25,
                          92,
                          112,
                          199,
                          49,
                          140,
                          135,
                          160,
                          20,
                          185,
                          171,
                          23,
                          98,
                          150,
                          177,
                          198,
                          61,
                          92,
                          26,
                          147,
                          164,
                          144,
                          51,
                          196,
                          42,
                          109,
                          194,
                          177,
                          100,
                          99,
                          99,
                          125,
                          143,
                          12,
                          76,
                          192,
                          152,
                          11,
                          152,
                          124,
                          197,
                          123,
                          147,
                          95,
                          73,
                          124,
                          45,
                          86,
                          168,
                          24,
                          34,
                          133,
                          120,
                          85,
                          81,
                          163,
                          146,
                          75,
                          92,
                          198,
                          126,
                          191};
    Solution::maxArea(height);
}