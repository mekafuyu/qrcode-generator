#pragma once

namespace qr_code_gen {
    void squarePattern(int x_start,int  y_start, int sqr_size, int qr_size, bool *content);
    void toggleCell(int x, int y, int qr_size, bool *content);
}