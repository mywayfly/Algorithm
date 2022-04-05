
// https://leetcode.com/problems/word-search/
// Early stop and optimization for bigger board and longer word

#include <vector>
#include <string>
class LeetCode79
{
private:
    int M = 0, N = 0;
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool findWord(std::vector<std::vector<char>>& board, int row, int col, std::string& word, int idx)
    {
        if(idx == word.size())
        {
            return true;
        }

        for(int i = 0; i < 4; ++i)
        {
            int x = row + dirs[i][0], y = col + dirs[i][1];
            if(x < 0 || x >= M || y < 0 || y >= N || board[x][y] != word[idx])
            {
                continue;
            }

            board[x][y] = '$';
            if(findWord(board, x, y, word, idx + 1))
            {
                return true;
            }
            
            board[x][y] = word[idx];
        }

        return false;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        M = board.size(), N = board[0].size();
        int len = word.size();
        if(len > M * N)
        {
            return false;
        }
        
        unordered_map<char, int> freq;
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                ++freq[board[i][j]];
            }
        }
        
        for(int i = 0; i < len; ++i)
        {
            if(!freq.count(word[i]) || freq[word[i]] == 0)
            {
                return false;
            }
            
            --freq[word[i]];
        }
        
        for(int i = 0; i < M; ++i)
        {
            for(int j = 0; j < N; ++j)
            {
                if(board[i][j] != word[0])
                {
                    continue;
                }
                
                board[i][j] = '$';
                if(findWord(board, i, j, word, 1))
                {
                    return true;
                }
                
                board[i][j] = word[0];
            }
        }

        return false;
    }
};

