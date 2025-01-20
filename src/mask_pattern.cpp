#include "mask_pattern.hpp"
#include "qr_code_patterns.hpp"

namespace qr_code_gen
{
    void maskA(int qr_size, bool *content)
    {
        for (int i = 0; i < qr_size; i++)
        {
            for (int j = 0; j < qr_size; j++)
            {
                if(j % 3 == 0)
                {
                    toggleCell(j, i, qr_size, content);
                }
            }
        }
    }    
    void maskB(int qr_size, bool *content)
    {
        for (int i = 0; i < qr_size; i++)
        {
            for (int j = 0; j < qr_size; j++)
            {
                if((i + j) % 3 == 0)
                {
                    toggleCell(j, i, qr_size, content);
                }
            }
        }
    }
    void maskC(int qr_size, bool *content)
    {
        for (int i = 0; i < qr_size; i++)
        {
            for (int j = 0; j < qr_size; j++)
            {
                if((i + j) % 2 == 0)
                {
                    toggleCell(j, i, qr_size, content);
                }
            }
        }
    }
    void maskD(int qr_size, bool *content)
    {
        for (int i = 0; i < qr_size; i++)
        {
            for (int j = 0; j < qr_size; j++)
            {
                if(i % 2 == 0)
                {
                    toggleCell(j, i, qr_size, content);
                }
            }
        }
    }
}


