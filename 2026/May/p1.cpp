#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> build(const vector<ll>& a, bool bigFirst) {
    int lo = 0, hi = (int)a.size() - 1;
    bool takeBig = bigFirst;
    vector<ll> res;
    while (lo <= hi) {
        if (takeBig) res.push_back(a[hi--]);
        else         res.push_back(a[lo++]);
        takeBig = !takeBig;
    }
    return res;
}

ll totalDiff(const vector<ll>& v) {
    ll s = 0;
    for (size_t i = 1; i < v.size(); i++) s += llabs(v[i] - v[i - 1]);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int m;
        cin >> m;
        vector<ll> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];
        sort(a.begin(), a.end());

        ll ans = max(totalDiff(build(a, true)), totalDiff(build(a, false)));
        cout << ans << "\n";
    }
    return 0;
}
