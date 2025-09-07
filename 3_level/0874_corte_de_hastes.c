#include <stdio.h>

int main ()
{
    while(1)
    {
        int n;
        scanf("%d", &n);
        
        if (n == 0)
            return 0;

        int p[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        
        int dp[n + 1];
        for(int i = 0; i < n + 1; i++)
            dp[i] = -99999999;
    
        dp[0] = 0;
        dp[1] = p[0];
        for (int i = 1; i <= n; i++)
        {
            int max = 0;
            for (int j = 1; j <= i; j++)
                if (max < dp[i - j] + p[j - 1])
                    max = dp[i - j] + p[j - 1];

            dp[i] = max;
        }
        
        printf("%d\n", dp[n]);
    }
}