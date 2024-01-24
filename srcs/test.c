#include <string.h>
#include <stdio.h>
int main()
{
    int tmp[1200];
    tmp[12] = 12;
    char c  = 'v';

    // tmp[strchr("avion", 'r')[0]] = 12;
    printf("%i\n", tmp[strchr("avion", c) ? tmp[strchr("avion", c)[0]] = 14 : 12]);
}