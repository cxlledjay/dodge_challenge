#include "game_include/misc.h"


void Sub_Score_a(unsigned int a, void* x)
{
    /// convert a to bcd
    unsigned int hun = 0;
    unsigned int ten = 0;
    unsigned int one = 0;
    while(a >= 100){a -= 100; ++hun;}
    while(a >= 10){a -= 10; ++ten;}
    while(a >= 1){a -= 1; ++one;}
    /// ...and save as array
    unsigned int substr[6] = {0,0,0,0,0,0};
    substr[5] = one;
    substr[4] = ten;
    substr[3] = hun;

    /// convert score (saved as ascii bcd array) to bcd array
    unsigned int score[6];
    unsigned int val;
    for(unsigned int i = 0; i < 6; ++i)
    {
        val = ((unsigned int*) x)[i];
        score[i] = (val == 32) ? 0 : val - 48;
    }

    /// actual bcd substraction
    unsigned int top, bot;
    for(int i = 5; i > -1; --i)
    {
        top = score[i];
        bot = substr[i];

        if(bot > top)
        {
            top += 10;
            substr[i-1]++; //< carry
        }

        /// write back in ascii format
        ((unsigned int*)x)[i] = (top - bot) + 48;
    }

    /// strip zeroes
    unsigned int had_a_char = 0;
    for(int i = 0; i < 6; ++i)
    {
        if(!had_a_char)
        {
            if(((char*)x)[i] == '0')
            {
                ((char*)x)[i] = ' ';
            }
            else 
            {
                had_a_char = 1;
            }
        }
    }
}
