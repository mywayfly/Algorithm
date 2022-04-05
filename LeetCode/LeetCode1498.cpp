
// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/
// Time complexity: O(N*logN)
// Space complexity: O(N)

#include <vector>
#include <algorithm>
class LeetCode1498
{
public:
    int numSubseq(std::vector<int>& nums, int target)
    {
        int const MOD = 1e9 + 7;
        std::sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = 0, left = 0, right = len - 1;
        std::vector<int> pows(len, 1);
        for(int i = 1; i < len; ++i)
        {
            pows[i] = pows[i - 1] * 2 % MOD;
        }

        while(left <= right)
        {
            if(nums[left] + nums[right] > target)
            {
                --right;
            }
            else
            {
                res = (res + pows[right - left]) % MOD;
                ++left;
            }
        }

        return res;
    }
};

