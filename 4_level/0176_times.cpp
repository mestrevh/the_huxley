#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n, t;
    cin >> n >> t;

    vector <pair<int, string>> p;

    for (int i = 0; i < n; i++)
    {
        string s;
        int v;
        cin >> s >> v;

        p.push_back({v, s});
    }

    sort(p.begin(), p.end());
    
    vector <vector <string>> team(t, vector <string>());

    for (int i = n - 1, j = 0; i >= 0; i--, j++)
        team[j % t].push_back(p[i].second);
    
    for (int i = 0; i < t; i++)
    {
        cout << "Time " << (i + 1) << '\n';

        sort(team[i].begin(), team[i].end());

        for (auto s: team[i])
            cout << s << '\n';

        cout << '\n';
    }

    return 0;
}