#include "qr_code_patterns.hpp"

namespace qr_code_gen
{
    void squarePattern(int x_start,int  y_start, int sqr_size, int qr_size, bool *content){
        
        for (char i = 0; i < sqr_size; i++)
        {
            toggleCell(x_start, y_start + i, qr_size, content);
            toggleCell(x_start + i + 1, y_start, qr_size, content);
            toggleCell(x_start + sqr_size, y_start + i + 1, qr_size, content);
            toggleCell(x_start + i, y_start + sqr_size, qr_size, content);
        }
        for (char i = 0; i < sqr_size - 3; i++)
        {
            for (char j = 0; j < sqr_size - 3; j++)
            {
                toggleCell(x_start + 2 + i, y_start + 2 + j, qr_size, content);
            }
        }

        // for i in range(size - 3):
        //     for j in range(size - 3):
        //         self.grid[y_start + 2 + i][x_start + 2 + j] = 1
        
        
        // for i in range(size):
        //         self.grid[y_start + i][x_start] = 1
        //         self.grid[y_start][x_start + i + 1] = 1
        //         self.grid[y_start + i + 1][x_start + size] = 1
        //         self.grid[y_start + size][x_start + i] = 1
    }
    void toggleCell(int x, int y, int qr_size, bool *content)
    {
        int curr = x + (qr_size * (qr_size - 1 - y));
        content[curr] = !content[curr];
    }
    void squarePatterns(int sqr_size, int qr_size, bool *content)
    {
        int offset = qr_size - (sqr_size + 2);
        squarePattern(1, 1, sqr_size, qr_size, content);
        squarePattern(offset, 1, sqr_size, qr_size, content);
        squarePattern(1, offset, sqr_size, qr_size, content);
        
    }
    void maskPattern(int mask, int qr_size, bool *content)
    {
    }
}