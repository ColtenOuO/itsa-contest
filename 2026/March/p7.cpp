#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> st;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll cur = a[i];

        while (!st.empty() && cur > st.back()) {
            ll top = st.back();

            if (st.size() == 1 || cur <= st[st.size() - 2]) {
                ans += cur;
                st.pop_back();
            } else {
                ll left = st[st.size() - 2];
                ans += left;
                st.pop_back();
            }
        }

        st.push_back(cur);
    }

    while (st.size() >= 2) {
        st.pop_back();
        ans += st.back();
    }

    cout << ans << "\n";
    return 0;
}
