
// https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>
class LeetCode22
{
private:
    void generateParenthesis(std::vector<string> &result, std::string& res, int openNum, int closeNum, int n)
    {
        if(res.size() == 2 * n)
        {
            result.push_back(res);
            return;
        }

        if(openNum >= closeNum && openNum < n)
        {
            res.push_back('(');
            generateParenthesis(result, res, openNum + 1, closeNum, n);
            res.pop_back();
        }

        if(closeNum < openNum && closeNum < n)
        {
            res.push_back(')');
            generateParenthesis(result, res, openNum, closeNum + 1, n);
            res.pop_back();
        }
    }
public:
    std::vector<string> generateParenthesis(int n)
    {
        std::vector<string> result;
        std::string res;
        generateParenthesis(result, res, 0, 0, n);
        return result;
    }
};

