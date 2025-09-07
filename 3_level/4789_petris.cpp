/*
    Código gerado pelo Gemini 2.5 Pro
*/

#include <bits/stdc++.h>

using namespace std;

void solve_case(int case_num) {
    vector<stack<int>> board;
    
    string s_input;
    int c_input;

    while (cin >> s_input && s_input != "END") {
        cin >> c_input;
        int s_pos = stoi(s_input);
        int n = board.size();

        if (s_pos == 0) {
            stack<int> new_col;
            new_col.push(c_input);
            board.insert(board.begin(), new_col);
        }
        else if (s_pos == n + 1) {
            stack<int> new_col;
            new_col.push(c_input);
            board.push_back(new_col);
        } 
        else {
            int col_idx = s_pos - 1;

            if (!board[col_idx].empty() && board[col_idx].top() == c_input) {
                while (!board[col_idx].empty() && board[col_idx].top() == c_input) {
                    board[col_idx].pop();
                }
                if (board[col_idx].empty()) {
                    board.erase(board.begin() + col_idx);
                }
            } else {
                board[col_idx].push(c_input);
            }
        }
    }

    cout << "caso " << case_num << ":";
    if (!board.empty()) {
        for (size_t i = 0; i < board.size(); ++i) {
            cout << " " << board[i].top();
        }
    }
    cout << endl;
}

int main() 
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p;
    cin >> p;

    for (int i = 0; i < p; ++i) {
        solve_case(i);
    }

    return 0;
}