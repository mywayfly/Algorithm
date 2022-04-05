
#include <unordered_map>
#include <vector>

class LeetCode219
{
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> val2idx;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            if(val2idx.count(nums[i]))
            {
                if(i - val2idx[nums[i]] <= k)
                {
                    return true;
                }
            }

            val2idx[nums[i]] = i;
        }

        return false;
    }
};