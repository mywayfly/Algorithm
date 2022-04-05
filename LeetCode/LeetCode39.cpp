
#include <vector>
class LeetCode39
{
private:
    void backtrack(std::vector<int>& candidates, int idx, std::vector<std::vector<int>>& result, std::vector<int>& res, int target)
    {
        if(target == 0)
        {
            result.push_back(res);
            return;
        }

        if(idx == candidates.size())
        {
            return;
        }

        backtrack(candidates, idx + 1, result, res, target);
        if(target >= candidates[idx])
        {
            res.push_back(candidates[idx]);
            backtrack(candidates, idx, result, res, target - candidates[idx]);
            res.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target)
    {
        std::vector<std::vector<int>> result;
        std::vector<int> res;
        backtrack(candidates, 0, result, res, target);
        return result;
    }
};
