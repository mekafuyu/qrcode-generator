#include "qr_code_patterns.hpp"
#include "mask_pattern.hpp"
#include "bmp_builder.hpp"

#include <iostream>
#include <fstream>
#include <bitset>


int main(int argc, const char * argv[])
{
    const int qr_size = 32;
    const int total_size = qr_size * qr_size;

    bool content[total_size];
    for (int i = 0; i < total_size; i++)
    {
       content[i] = false;
    }

    // qr_code_gen::squarePatterns(6, qr_size, content);
    qr_code_gen::maskB(qr_size, content);
    // qr_code_gen::toggleCell(0, 2, qr_size, content);
    // qr_code_gen::toggleCell(2, 0, qr_size, content);
    
    

    qr_code_gen::BMP_builder bmp = qr_code_gen::BMP_builder();

    bmp.write(qr_size, 10, content);
    std::cout << "The BMP has been written.\n" << std::endl;

    return 0;
}