
// https://leetcode.com/problems/3sum/
// Time omplexity:
// Space complexity:

#include <vector>
#include <algorithm>
class LeetCode15
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> result;
        int len = nums.size();
        if(len < 3)
        {
            return result;
        }

        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < len; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            int twoSum = 0 - nums[i];
            int left = i + 1, right = len - 1;
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                if(sum == twoSum)
                {
                    result.push_back(std::vector<int>({nums[i], nums[left], nums[right]}));
                }
                    
                if (sum <= twoSum)
                {
                    ++left;
                    while(left < right && nums[left - 1] == nums[left])
                    {
                        ++left;
                    }
                }
                else
                {
                    --right;
                    while(left < right && nums[right] == nums[right + 1])
                    {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};