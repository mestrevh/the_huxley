/*
    Gerado pelo Gemini Pro 2.5
*/

#include <bits/stdc++.h>

using namespace std;

int solve_lps(const string& s) {

    int n = s.length();

    if (n == 0) {
        return 0;
    }

    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == s_rev[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];

            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            }
        }
    }

    return dp[n][n];
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--) {
        string word;
        getline(cin, word);

        if (!word.empty() && word.back() == '\r') {
            word.pop_back();
        }
        cout << solve_lps(word) << endl;
    }

    return 0;
}