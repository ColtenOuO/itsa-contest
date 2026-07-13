#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    vector<vector<int>> g(R, vector<int>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> g[i][j];

    int sr, sc, tr, tc;
    cin >> sr >> sc >> tr >> tc;

    vector<vector<bool>> vis(R, vector<bool>(C, false));
    queue<pair<int,int>> q;

    if (g[sr][sc] == 0) {
        vis[sr][sc] = true;
        q.push({sr, sc});
    }

    bool reach = false;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == tr && y == tc) {
            reach = true;
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && !vis[nx][ny] && g[nx][ny] == 0) {
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << (reach ? "true" : "false") << "\n";
    return 0;
}
