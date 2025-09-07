#include <stdio.h>
#include <limits.h>

int main ()
{
    int n;
    scanf("%d", &n);

    long long a[n];
    
    for (int i = 0; i < n; i++)
        scanf("%llu", &a[i]);
    

    long long max1 = LLONG_MIN, max2 = LLONG_MIN;
    
    for (int i = 0; i < n; i++) {
        long long v1 = a[i] + i;
        long long v2 = a[i] - i;

        if (v1 > max1) max1 = v1;
        if (v2 > max2) max2 = v2;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long v1 = a[i] - i;
        long long v2 = a[i] + i;

        if (max1 + v1 > ans) ans = max1 + v1;
        if (max2 + v2 > ans) ans = max2 + v2;
    }

    printf("%lld\n", ans);
    
    return 0;
}