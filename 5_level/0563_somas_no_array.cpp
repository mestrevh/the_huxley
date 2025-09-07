/*
    Gerado pelo Gemini Pro 2.5
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int len, p;
    cin >> len >> p;

    vector<int> val(len);
    int total_sum = 0;
    for (int i = 0; i < len; i++) {
        cin >> val[i];
        total_sum += val[i];
    }

    vector<vector<bool>> dp(len + 1, vector<bool>(total_sum + 1, false));

    for (int i = 0; i <= len; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= total_sum; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j >= val[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - val[i - 1]];
            }
        }
    }

    for (int i = 0; i < p; i++) {
        int num, k;
        cin >> num >> k;

        if (k < 0 || k > total_sum) {
            cout << " 0";
        } else {
            if (dp[num][k]) {
                cout << " 1";
            } else {
                cout << " 0";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int c = 1; c <= n; c++) {
        cout << "caso " << c << ":";
        solve();
        cout << "\n";
    }

    return 0;
}