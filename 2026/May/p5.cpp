#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    while (cin >> R >> C) {
        vector<string> g(R);
        for (int i = 0; i < R; i++) cin >> g[i];

        vector<vector<bool>> scanned(R, vector<bool>(C, false));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (g[i][j] == 'b') {
                    scanned[i][j] = true;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d], nj = j + dy[d];
                        if (ni >= 0 && ni < R && nj >= 0 && nj < C)
                            scanned[ni][nj] = true;
                    }
                } else if (g[i][j] == 'B') {
                    scanned[i][j] = true;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dx[d], nj = j + dy[d];
                        while (ni >= 0 && ni < R && nj >= 0 && nj < C && g[ni][nj] != '1') {
                            scanned[ni][nj] = true;
                            ni += dx[d];
                            nj += dy[d];
                        }
                    }
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (g[i][j] == '0' && !scanned[i][j]) cnt++;

        cout << cnt << "\n";
    }
    return 0;
}
