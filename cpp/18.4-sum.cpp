/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.90%)
 * Likes:    1367
 * Dislikes: 269
 * Total Accepted:    276.7K
 * Total Submissions: 867.3K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        unsigned numNums = nums.size();
        if (numNums <= 3)
        {
            return {};
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (unsigned i = 0; i != numNums - 3; ++i)
        {
            const int a = nums[i];
            if (a * 4 > target)
            {
                return ret;
            }

            if (i && a == nums[i - 1])
            {
                continue;
            }

            for (unsigned j = i + 1; j != numNums - 2; ++j)
            {
                const int b = nums[j];
                if (a + b * 3 > target)
                {
                    break;
                }

                if (j > i + 1 && b == nums[j - 1])
                {
                    continue;
                }

                int l = j + 1;
                int h = numNums - 1;
                while (l < h)
                {
                    const int c = nums[l];
                    const int d = nums[h];
                    if (a + b + c * 2 > target)
                    {
                        break;
                    }

                    if (a + b + c + d > target)
                    {
                        for (--h; h != j + 1 && nums[h] == d; --h)
                            ;
                    }
                    else if (a + b + c + d < target)
                    {
                        for (++l; l != numNums - 1 && nums[l] == c; ++l)
                            ;
                    }
                    else
                    {
                        ret.push_back({a, b, c, d});
                        for (++l; l != numNums - 1 && nums[l] == c; ++l)
                            ;
                        for (--h; h != j + 1 && nums[h] == d; --h)
                            ;
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
