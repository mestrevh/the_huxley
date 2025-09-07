#include <bits/stdc++.h>

using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string word;

    vector <long long> fat(16, 1);

    for (int i = 1; i <= 15; i++)
        fat[i] = fat[i - 1] * i;

    while (1)
    {
        cin >> word;

        if (word == "0")
            return 0;

        set <char> conj;
        for (int i = 0; word[i] != '\0'; i++)
        {
            conj.insert(word[i]);
        }
        
        cout << fat[conj.size()] << '\n';
    }

}