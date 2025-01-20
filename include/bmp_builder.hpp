#pragma once

namespace qr_code_gen {
    class BMP_builder
    {
    private:
    public:
        void write(int qr_size, int qr_cell_size, bool* content);
        void insertIntIntoArray(unsigned int value, char numBytes, unsigned char *bytes);
        void drawCell(int offsetX, int offsetY, int qr_size, int qr_cell_size, unsigned char *bmp_content);
        BMP_builder();
        ~BMP_builder();
    };

}

