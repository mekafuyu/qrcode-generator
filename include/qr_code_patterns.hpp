#pragma once

namespace qr_code_gen {
    void toggleCell(int x, int y, int qr_size, bool *content);
    void squarePattern(int x_start,int  y_start, int sqr_size, int qr_size, bool *content);
    void squarePatterns(int sqr_size, int qr_size, bool *content);
    void maskPattern(int mask, int qr_size, bool *content);
}