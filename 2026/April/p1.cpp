#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double P, R;
    int N;
    cin >> P >> R >> N;

    double energy = 0;
    for (int i = 0; i < N; i++) {
        energy += P;
        energy *= (1 + R);
    }

    cout << energy << "\n";
    return 0;
}
