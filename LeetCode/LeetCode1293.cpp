
// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

#include <vector>
#include <queue>
#include <string> // memset
class LeetCode1293
{
public:
    int shortestPath(std::vector<std::vector<int>>& grid, int k)
    {
        int M = grid.size(), N = grid[0].size();
        if(M == 1 && N == 1)
        {
            return 0;
        }

        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        short seen[M][N];
        std::memset(seen, -1, sizeof(seen));
        std::queue<std::vector<int>> que;
        que.push(std::vector<int>({0, 0, k}));
        seen[0][0] = k;

        int step = 0;
        while(!que.empty())
        {
            ++step;
            int size = que.size();
            for(int i = 0; i < size; ++i)
            {
                auto vec = que.front();
                que.pop();
                for(int j = 0; j < 4; ++j)
                {
                    int x = vec[0] + dirs[j][0], y = vec[1] + dirs[j][1];
                    if(x < 0 || x >= M || y < 0 || y >= N)
                    {
                        continue;
                    }

                    if(x == M - 1 && y == N - 1)
                    {
                        return step;
                    }

                    int quota = vec[2] - grid[x][y];
                    if(quota >= 0 && quota > seen[x][y])
                    {
                        seen[x][y] = quota;
                        que.push(std::vector<int>({x, y, quota}));
                    }
                }
            }
        }

        return -1;
    }
};

