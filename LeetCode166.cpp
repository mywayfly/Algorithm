
// https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <string>
#include <utility>
#include <unordered_map>
#include <stdlib.h> // std::abs
#include <iostream>

class LeetCode166
{
private:
    inline std:: pair<long, long> getResultAndReminder(long numerator, long denominator)
    {
        long result = numerator / denominator;
        return {result, numerator - denominator * result};
    }

public:
    std::string fractionToDecimal(int numerator, int denominator)
    {
        string res = "";
        if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0)
        {
            res += '-';
        }
        
        long num = std::abs(numerator);
        long deno = std::abs(denominator);
        std::unordered_map<int, uint16_t> rem2idx;
        auto kv = getResultAndReminder(num, deno);
        long reminder = kv.second;
        res += std::to_string(kv.first);
        if(reminder == 0)
        {
            return res;
        }

        res += ".";
        while(reminder != 0 && !rem2idx.count(reminder))
        {
            rem2idx[reminder] = res.size();
            auto kv1 = getResultAndReminder(reminder * 10, deno);
            res += std::to_string(kv1.first);
            reminder = kv1.second;
        }

        if(reminder != 0)
        {
            //res.insert(rem2idx[reminder], "(");
            res.insert(res.begin() + rem2idx[reminder], '(');
            res.push_back(')');
        }
        
        return res;    
    }
};

