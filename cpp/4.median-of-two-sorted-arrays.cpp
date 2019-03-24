/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.34%)
 * Total Accepted:    375.7K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution
{
  private:
    double median(const vector<int> &gnums, const unsigned gb, const unsigned ge)
    {
        if ((ge - gb) % 2)
        {
            return gnums[gb + (ge - gb) / 2];
        }
        else
        {
            return (gnums[gb + (ge - gb) / 2 - 1] + gnums[gb + (ge - gb) / 2]) / 2.0;
        }
    }

  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> *lnums;
        vector<int> *gnums;
        if (nums1.size() <= nums2.size())
        {
            lnums = &nums1;
            gnums = &nums2;
        }
        else
        {
            lnums = &nums2;
            gnums = &nums1;
        }
        unsigned lb = 0;
        unsigned gb = 0;
        unsigned le = lnums->size();
        unsigned ge = gnums->size();
        while (true)
        {
            if (lb == le)
            {
                return median(*gnums, gb, ge);
            }
            else if (lb + 2 >= le)
            {
                const unsigned ngb = gb + max((ge - gb + 1) / 2, 2U) - 2;
                const unsigned nge = min(gb + (ge - gb) / 2 + 2, ge);
                gnums->insert(gnums->begin() + nge, lnums->begin() + lb, lnums->begin() + le);
                sort(gnums->begin() + ngb, gnums->begin() + nge + le - lb);
                return median(*gnums, ngb, nge + le - lb);
            }
            const double lm = median(*lnums, lb, le);
            const double gm = median(*gnums, gb, ge);
            if (lm == gm)
            {
                return lm;
            }
            const unsigned delta = (le - lb - 1) / 2;
            if (lm < gm)
            {
                lb += delta;
                ge -= delta;
            }
            else
            {
                le -= delta;
                gb += delta;
            }
        }
    }
};
