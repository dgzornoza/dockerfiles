#include "z88dk_headers.h"
#include <stdlib.h>

int a[5] = {0, 1, 2, 3, 4};

extern void neg_and_triple_a(void); // implemented elsewhere

void negate_odd_a(void)
{
    for (int i = 0; i != 5; ++i)
    {
        if (a[i] & 0x01)
        {
            a[i] = -a[i]; // negate odd numbers in array a[]
        }
    }

    return;
}

void plot(unsigned char x, unsigned char y)
{
    unsigned char *screen_address = zx_pxy2saddr(x, y);
    unsigned char bitmask = 1 << (7 - (x % 8));
    *screen_address |= bitmask;
}

int main(void)
{
    unsigned char i;

    neg_and_triple_a(); // call to asm subroutine

    for (i = 0; i < 15; i++)
    {
        plot(rand() % 256, rand() % 192);
    }

    return 0;
}

/* C source end */