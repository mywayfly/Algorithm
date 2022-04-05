

// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

#include <vector>
#include <stdlib.h>
class LeetCode1275
{
public:
    std::string tictactoe(std::vector<std::vector<int>>& moves)
    {
        int const N = 3;
        std::vector<int> rows(N, 0), cols(N, 0), diags(2, 0);
        int len = moves.size();
        for(int i = 0; i < len; ++i)
        {
            // A: -1, B: 1
            int gain = i & 0x1 ? 1 : -1;
            rows[moves[i][0]] += gain;
            cols[moves[i][1]] += gain;
            if(moves[i][0] == moves[i][1])
            {
                diags[0] += gain;
            }

            if(moves[i][0] + moves[i][1] == 2)
            {
                diags[1] += gain;
            }
            
            if(std::abs(rows[moves[i][0]]) == N || std::abs(cols[moves[i][1]]) == N || std::abs(diags[0]) == N || std::abs(diags[1]) == N)
            {
                return i & 0x1 ? "B" : "A";
            }
        }

        return len == 9 ? "Draw" : "Pending";
    }
};
