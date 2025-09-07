#include <bits/stdc++.h>

using namespace std;

int main()
{

    for (int i = 1;; i++)
    {
        int n;
        cin >> n;

        if (n == 0)
            return 0;

        vector<int> ac(n);

        for (int j = 0; j < n; j++)
        {
            int x, y;
            cin >> x >> y;

            ac[j] = (x - y);
        }

        int max = INT_MIN, x = 0, y = 0;
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int k = j; k < n; k++)
            {
                count += ac[k];

                if (count > max)
                {
                    max = count;
                    x = j + 1;
                    y = k + 1;
                }
                else if (count == max)
                {
                    if ( (k + 1) - (j + 1) > y - x)
                    {
                        x = j + 1;
                        y = k + 1;
                    }
                }
            }
        }

        cout << "Teste " << i << '\n';
        if (max > 0)
        {
            cout << x << " " << y << '\n';
        }
        else
        {
            cout << "nenhum\n";
        }

        cout << '\n';
    }
}