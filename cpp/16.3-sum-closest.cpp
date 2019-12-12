/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.70%)
 * Likes:    1465
 * Dislikes: 107
 * Total Accepted:    399.1K
 * Total Submissions: 873.2K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        unsigned numNums = nums.size();
        if (numNums <= 2)
        {
            return target;
        }

        long long ret = 0;
        if (target < 0)
        {
            ret = INT_MAX;
        }
        else
        {
            ret = INT_MIN;
        }

        sort(nums.begin(), nums.end());
        for (unsigned i = 0; i != numNums - 2; ++i)
        {
            const int a = nums[i];
            if (i && nums[i] == nums[i - 1])
            {
                continue;
            }
            int l = i + 1;
            int h = numNums - 1;
            while (l < h)
            {
                int b = nums[l];
                int c = nums[h];
                int s = a + b + c;
                if (s == target)
                {
                    return target;
                }

                if (abs(s - target) < abs(ret - target))
                {
                    ret = s;
                }

                if (s > target)
                {
                    for (--h; h != i + 1 && nums[h] == c; --h)
                        ;
                }
                else if (s < target)
                {
                    for (++l; l != numNums - 1 && nums[l] == b; ++l)
                        ;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
