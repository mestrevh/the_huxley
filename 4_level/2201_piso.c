#include <stdio.h>

int main ()
{
    int l, h;
    scanf("%d %d", &h, &l);

    int t1 = (l * h) + ((l - 1) * (h - 1));
    int t2 = (l - 1) * 2 + (h - 1) * 2;

    printf("%d\n%d\n", t1, t2);
}