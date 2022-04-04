
// https://leetcode.com/problems/strobogrammatic-number-ii/
// Time complexity: N * 5^N/2
// Space complexity:


#include <vector>

class LeetCode247
{
public:
    std::vector<std::string> findStrobogrammatic(int n)
    {
        std::vector<std::vector<std::string>> vec;
        vec.push_back(std::vector<std::string>({""}));
        vec.push_back(std::vector<std::string>({"0", "1", "8"}));
        int idx = n & 0x1 ? 1 : 0;
        while(n > 1)
        {
            n -= 2;
            std::vector<std::string> res;
            for(auto& ele : vec[idx])
            {
                // add "0" and "0" as prefix and suffix if and only if we have a next iteration
                if(n > 1)
                {
                    res.push_back("0" + ele + "0");
                }

                res.push_back("1" + ele + "1");
                res.push_back("6" + ele + "9");
                res.push_back("8" + ele + "8");
                res.push_back("9" + ele + "6");
            }

            vec[idx].swap(res);
        }

        return vec[idx];
    }
};