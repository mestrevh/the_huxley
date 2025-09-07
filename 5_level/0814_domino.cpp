#include <bits/stdc++.h>

using namespace std;

const int MAXV = 7;

void dfs (int v, vector <vector <int>> &g, vector <bool> &vist)
{
    vist[v] = true;

    for(int u: g[v])
        if (!vist[u])
            dfs(u, g, vist);
}

bool conexo (vector <vector <int>> &g, set <int> &vert)
{
    if (vert.empty())
        return true;

    vector <bool> vist(MAXV, false);
    int start = *vert.begin();

    dfs(start, g, vist);

    for (int v: vert)
        if (!vist[v]) return false;
    
    return true;
}

int main ()
{
    for (int i = 1; ; i++)
    {
        int n;
        cin >> n;

        if (n == 0)
            return 0;

        vector <vector <int>> g(MAXV);
        vector <int> grau (MAXV, 0);
        set<int> vert;

        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;

            g[u].push_back(v);
            g[v].push_back(u);
            grau[u]++;
            grau[v]++;
            vert.insert(u);
            vert.insert(v);
        }

        bool c = conexo(g, vert);
        int count = 0;

        for (int g: grau)
            if (g % 2 == 1) count++;
        
        cout << "Teste " << i << "\n";
        if (c && (count == 0 || count == 2)) {
            cout << "sim\n";
        } else {
            cout << "nao\n";
        }
        cout << "\n";
    }
}