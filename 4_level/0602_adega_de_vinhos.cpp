#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    vector < vector <int> > dp (n + 1, vector <int> (n + 1, 0));

    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            int x = j + i - 1;

            int y = n - (x - j);

            if (x == j)
            {
                dp[j][j] = y * p[j];
            }
            else
            {
                dp[j][x] = max(p[j] * y + dp[j + 1][x], p[x] * y + dp[j][x - 1]);
            }
        }
        
    }
    
    cout << dp[0][n - 1] << '\n';

    return 0;
}