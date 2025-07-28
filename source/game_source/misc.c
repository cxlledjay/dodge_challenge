#include "game_include/misc.h"


void convert_bin_to_bcd (long bin, int * bcd, unsigned int bcd_len)
{
    /// stolen from the internet
    long bcd_res = 0;
    long shift = 0;

    while (bin > 0) {
        bcd_res |= (bin % 10) << (shift++ << 2);
        bin /= 10;
    }

    /// write to array
    for(unsigned int i = bcd_len; i > 0; --i)
    {
        bcd[i] = (int) ((bcd_res >> ((bcd_len - i) * 4)) &0x0F);
    }
}