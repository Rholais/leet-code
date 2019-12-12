/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.22%)
 * Likes:    4897
 * Dislikes: 584
 * Total Accepted:    703.2K
 * Total Submissions: 2.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        unsigned numNums = nums.size();
        if (numNums <= 2)
        {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (unsigned i = 0; i != numNums - 2; ++i)
        {
            const int a = nums[i];
            if (a > 0)
            {
                return ret;
            }

            if (i && a == nums[i - 1])
            {
                continue;
            }
            int l = i + 1;
            int h = numNums - 1;
            while (l < h)
            {
                int b = nums[l];
                int c = nums[h];
                if (a + b + c > 0)
                {
                    for (--h; h != i + 1 && nums[h] == c; --h)
                        ;
                }
                else if (a + b + c < 0)
                {
                    for (++l; l != numNums - 1 && nums[l] == b; ++l)
                        ;
                }
                else
                {
                    ret.push_back({a, b, c});
                    for (++l; l != numNums - 1 && nums[l] == b; ++l)
                        ;
                    for (--h; h != i + 1 && nums[h] == c; --h)
                        ;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
