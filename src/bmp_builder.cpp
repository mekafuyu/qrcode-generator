#include "bmp_builder.hpp"
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

namespace qr_code_gen
{
    void BMP_builder::write(int qr_size, int qr_cell_size, bool *content)
    {
        unsigned char bmp_headers[] = {
            0x42, 0x4D,             // Signature 'BM'
            0xaa, 0x00, 0x00, 0x00, // Size: 170 bytes
            0x00, 0x00,             // Unused
            0x00, 0x00,             // Unused
            0x8a, 0x00, 0x00, 0x00, // Offset to image data

            0x7c, 0x00, 0x00, 0x00, // DIB header size (124 bytes)
            0x04, 0x00, 0x00, 0x00, // Width (4px)
            0x02, 0x00, 0x00, 0x00, // Height (2px)
            0x01, 0x00,             // Planes (1)
            0x20, 0x00,             // Bits per pixel (32)
            0x03, 0x00, 0x00, 0x00, // Format (bitfield = use bitfields | no compression)
            0x20, 0x00, 0x00, 0x00, // Image raw size (32 bytes)
            0x13, 0x0B, 0x00, 0x00, // Horizontal print resolution (2835 = 72dpi * 39.3701)
            0x13, 0x0B, 0x00, 0x00, // Vertical print resolution (2835 = 72dpi * 39.3701)
            0x00, 0x00, 0x00, 0x00, // Colors in palette (none)
            0x00, 0x00, 0x00, 0x00, // Important colors (0 = all)
            0x00, 0x00, 0xFF, 0x00, // R bitmask (00FF0000)
            0x00, 0xFF, 0x00, 0x00, // G bitmask (0000FF00)
            0xFF, 0x00, 0x00, 0x00, // B bitmask (000000FF)
            0x00, 0x00, 0x00, 0xFF, // A bitmask (FF000000)
            0x42, 0x47, 0x52, 0x73, // sRGB color space
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // Unused R, G, B entries for color space
            0x00, 0x00, 0x00, 0x00, // Unused Gamma X entry for color space
            0x00, 0x00, 0x00, 0x00, // Unused Gamma Y entry for color space
            0x00, 0x00, 0x00, 0x00, // Unused Gamma Z entry for color space

            0x00, 0x00, 0x00, 0x00, // Unknown
            0x00, 0x00, 0x00, 0x00, // Unknown
            0x00, 0x00, 0x00, 0x00, // Unknown
            0x00, 0x00, 0x00, 0x00, // Unknown                                                                                                                                                                                               // Unknown
        };

        const int img_size = qr_size * qr_cell_size;
        const int content_byte_size = img_size * img_size * 4;
        const int total_byte_size = sizeof(bmp_headers) + content_byte_size;

        unsigned char* bmp_content = new unsigned char[content_byte_size];

        for (int i = 0; i < content_byte_size; i++)
        {
            bmp_content[i] = 0xFF;
        }

        for (int i = 0; i < qr_size * qr_size; i++)
        {
            if(content[i])
            {
                int x = i % qr_size;
                int y = i / qr_size;
                drawCell(x, y, qr_size, qr_cell_size, bmp_content);
            }
        }

        insertIntIntoArray(total_byte_size, 4, bmp_headers + 2);
        insertIntIntoArray(img_size, 4, bmp_headers + 18);
        insertIntIntoArray(img_size, 4, bmp_headers + 22);
        insertIntIntoArray(content_byte_size, 4, bmp_headers + 34);

        fstream fs("qrcode.bmp", ios_base::out | ios_base::binary);
        fs.write((const char *)bmp_headers, sizeof(bmp_headers));
        fs.write((const char *)bmp_content, content_byte_size);
        fs.close();

        delete[] bmp_content;
    }

    void BMP_builder::insertIntIntoArray(unsigned int value, char numBytes, unsigned char *bytes)
    {
        for (char i = 0; i < numBytes; i++)
        {
            bytes[i] = (unsigned char)(value >> (i * 8));
        }
    }

    void BMP_builder::drawCell(int offsetX, int offsetY, int qr_size, int qr_cell_size, unsigned char *bmp_content)
    {
        int offset =
            offsetX * qr_cell_size * 4 +
            offsetY * qr_cell_size * qr_cell_size * qr_size * 4;

        for (int i = 0; i < qr_cell_size; i++)
        {
            int y_offset = qr_cell_size * qr_size * 4 * i;
            for (int j = 0; j < qr_cell_size; j++)
            {
                bmp_content[offset + y_offset + j * 4] = 0x00;
                bmp_content[offset + y_offset + j * 4 + 1] = 0x00;
                bmp_content[offset + y_offset + j * 4 + 2] = 0x00;
            }
        }
    }

    BMP_builder::BMP_builder()
    {
    }
    BMP_builder::~BMP_builder()
    {
    }
}