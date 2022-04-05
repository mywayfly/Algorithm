
// https://leetcode.com/problems/product-of-array-except-self/
// Time complexity: O(n)
// Space complexity: O(1)

#include <vector>
class LeetCode238
{
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums)
    {
        int len = nums.size();
        std::vector<int> result(len, 1);
        for(int i = 1; i < len; ++i)
        {
           result[i] = result[i - 1] * nums[i - 1]; 
        }
    
        int suffix = 1;
        for(int i = len - 1; i >= 0; --i)
        {
            result[i] = result[i] * suffix;
            suffix *= nums[i];
        }
    
        return result;
    }
};