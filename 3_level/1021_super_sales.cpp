/*
    Gerado pelo Gemini Pro 2.5
*/

#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n_items;
    cin >> n_items;

    vector<pair<int, int>> items(n_items);
    for (int i = 0; i < n_items; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    vector<int> dp(31, 0);

    for (int i = 0; i < n_items; ++i) {
        int price = items[i].first;
        int weight = items[i].second;

        for (int w = 30; w >= weight; --w) {
            dp[w] = max(dp[w], price + dp[w - weight]);
        }
    }

    int n_people;
    cin >> n_people;

    long long total_value = 0;
    for (int i = 0; i < n_people; ++i) {
        int max_weight;
        cin >> max_weight;
        total_value += dp[max_weight];
    }

    cout << total_value << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}