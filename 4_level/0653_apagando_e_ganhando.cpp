#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d;
    while (cin >> n >> d && (n != 0 || d != 0)) {
        string numero;
        cin >> numero;

        string resultado = "";
        
        for (char digito : numero) {
            while (!resultado.empty() && d > 0 && digito > resultado.back()) {
                resultado.pop_back();
                d--;
            }
            resultado.push_back(digito);
        }

        while (d > 0) {
            resultado.pop_back();
            d--;
        }

        cout << resultado << endl;
    }
}

int main() {
    solve();
    return 0;
}