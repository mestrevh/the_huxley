#include <stdio.h>
#include <limits.h>

int check(int map[], int n, int pulo, int init)
{
    for (int i = init + pulo + 1; i < n; i += pulo + 1)
    {
        if (map[i])
        {
            return 0;
        }

        if (i + pulo + 1 < n && map[i + pulo + 1])
        {
            while(i < n && map[i] == 0)
                i++;
            
            i--;
        }
    }

    return 1;
}

int min_pulo(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n && array[j] == 0; j++)
        {
            if (check(array, n, i, j))
            {
                return i;
            }
        }
    }

    return -1;
}

int main()
{
    int n, max = 1;
    scanf("%d", &n);

    int p[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);

        if (p[i] > max)
            max = p[i];
    }

    int map[max + 2];

    for (int i = 0; i < max + 2; i++)
        map[i] = 0;

    for (int i = 0; i < n; i++)
        map[p[i]] = 1;

    for (int i = 0; i < max + 1; i++)
        printf("%d", map[i]);

    printf("\n");

    int min = min_pulo(map, max + 2);

    printf("Pulo minimo: %d\n", min);
}