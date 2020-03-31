/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 *
 * https://leetcode.com/problems/4sum-ii/description/
 *
 * algorithms
 * Medium (51.76%)
 * Likes:    846
 * Dislikes: 62
 * Total Accepted:    83.3K
 * Total Submissions: 160.8K
 * Testcase Example:  '[1,2]\n[-2,-1]\n[-1,2]\n[0,2]'
 *
 * Given four lists A, B, C, D of integer values, compute how many tuples (i,
 * j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 * 
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤
 * N ≤ 500. All integers are in the range of -2^28 to 2^28 - 1 and the result
 * is guaranteed to be at most 2^31 - 1.
 * 
 * Example:
 * 
 * 
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        if (A.empty())
        {
            return 0;
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());
        unsigned numNums = A.size();
        unsigned ret = 0;
        unsigned i = 0;
        while (i != numNums)
        {
            const int a = A[i];
            unsigned di = 1;
            for (++i; i != numNums && A[i] == a; ++i, ++di)
                ;
            //  if (i && a == A[i - 1]) { continue; }

            unsigned j = 0;
            while (j != numNums)
            {
                const int b = B[j];
                unsigned dj = 1;
                for (++j; j != numNums && B[j] == b; ++j, ++dj)
                    ;
                //  if (j && b == B[j - 1]) { continue; }

                unsigned l = 0;
                int h = numNums - 1;
                while (l != numNums && h >= 0)
                {
                    const int c = C[l];
                    const int d = D[h];
                    if (a + b + c + d > 0)
                    {
                        for (--h; h >= 0 && D[h] == d; --h)
                            ;
                    }
                    else if (a + b + c + d < 0)
                    {
                        for (++l; l != numNums && C[l] == c; ++l)
                            ;
                    }
                    else
                    {
                        int dl = 1;
                        for (++l; l != numNums && C[l] == c; ++l, ++dl)
                            ;
                        int dh = 1;
                        for (--h; h >= 0 && D[h] == d; --h, ++dh)
                            ;
                        ret += (di * dj * dl * dh);
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end
