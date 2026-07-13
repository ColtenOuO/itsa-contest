#include <bits/stdc++.h>
using namespace std;

char g[10][10];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 8; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= 8; j++) {
            g[i][j] = s[j - 1];
        }
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            bool flaw = false;
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (g[ni][nj] == g[i][j]) {
                    flaw = true;
                    break;
                }
            }
            if (flaw) {
                cout << i - 1 << " " << j - 1 << "\n";
            }
        }
    }

    return 0;
}
