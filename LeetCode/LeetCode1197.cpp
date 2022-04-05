

// https://leetcode.com/problems/minimum-knight-moves/

#include <queue>
#include <utility> // std::pair
#include <stdlib.h>

class LeetCode1197
{
public:
    int minKnightMoves(int x, int y)
    {
        if(x == 0 && y == 0)
        {
            return 0;
        }
        
        int dirs[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1,-2}};
        bool seen[607][607] = {false};
        std::queue<std::pair<int, int>> que;
        que.push({302, 302});
        seen[302][302] = true;
        x += 302;
        y += 302;
        int step = 0;
        while(!que.empty())
        {
            ++step;
            int size = que.size();
            for(int k = 0; k < size; ++k)
            {
				auto kv = que.front();
				que.pop();
                int row = kv.first, col = kv.second;
				for(int i = 0; i < 8; ++i)
				{
					int r = row + dirs[i][0], c = col + dirs[i][1];
                    if(r == x && c == y)
                    {
                        return step;
                    }
                    
                    if(seen[r][c])
                    {
                        continue;
                    }

                    seen[r][c] = true;
                    que.push({r, c});
				}
            }
        }

        return -1;
    }
};