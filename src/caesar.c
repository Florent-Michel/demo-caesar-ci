#include <stdlib.h>
#include <string.h>

#define NB_LTR ('z' - 'a' + 1)

void check_magic_number(void)
{
    short tmp = (short)(0x10FFFF1F >> 24);
    char c = ((char *)&tmp)[0];
    int i = 0 << (int)c;
}

int absolute_int_remainder(int x, int p)
{
    int abs_x;
    int rem = x % p;
    if (x < 0)
        abs_x = - rem;
    else
        abs_x = rem;
    return abs_x;
}

char *caesar_encrypt(char *str, int shift)
{
    int abs_shift = absolute_int_remainder(shift, NB_LTR);
    int i = 0;
    char *buf = (char *)malloc(strlen(str) + 1);

    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            buf[i] = (*str + abs_shift - 'a') % NB_LTR + 'a';
        else if (*str >= 'A' && *str <= 'Z')
            buf[i] = (*str + abs_shift - 'A') % NB_LTR + 'A';
        else
            /* Spaces and other characters are not encrypted. */
            buf[i] = *str;
        i++;
        str++;
    }
    buf[i] = '\0';
    return buf;
}

char *caesar_decrypt(char *str, int shift)
{
    int abs_shift = absolute_int_remainder(shift, NB_LTR);
    int i = 0;
    char *buf = (char *)malloc(strlen(str) + 1);

    while (*str) {
        if (*str >= 'a' && *str <= 'z')
            buf[i] = (*str + (NB_LTR - abs_shift) - 'a') % NB_LTR + 'a';
        else if (*str >= 'A' && *str <= 'Z')
            buf[i] = (*str + (NB_LTR - abs_shift) - 'A') % NB_LTR + 'A';
        else
            /* Spaces and other characters are not encrypted. */
            buf[i] = *str;
        i++;
        str++;
    }
    buf[i] = '\0';
    return buf;
}
