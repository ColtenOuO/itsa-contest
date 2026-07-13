#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, threshold;
    cin >> n >> threshold;

    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cnt[c]++;
    }

    vector<pair<int,int>> res;
    for (auto& [club, c] : cnt)
        if (c >= threshold)
            res.push_back({club, c});

    sort(res.begin(), res.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    for (auto& [club, c] : res)
        cout << club << " " << c << "\n";

    return 0;
}
