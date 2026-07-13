#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = LLONG_MAX / 4;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<ll>> mx(n + 2, vector<ll>(n + 1, 0));
    for (int L = 1; L <= n; L++) {
        mx[L][L] = a[L];
        for (int R = L + 1; R <= n; R++) mx[L][R] = max(mx[L][R - 1], a[R]);
    }

    vector<vector<ll>> dp(n + 2, vector<ll>(n + 1, 0));

    for (int len = 2; len <= n; len++) {
        for (int L = 1; L + len - 1 <= n; L++) {
            int R = L + len - 1;
            ll best = INF;
            for (int k = L; k < R; k++)
                best = min(best, dp[L][k] + dp[k + 1][R]);
            dp[L][R] = best + mx[L][R];
        }
    }

    cout << (n >= 1 ? dp[1][n] : 0) << "\n";
    return 0;
}
