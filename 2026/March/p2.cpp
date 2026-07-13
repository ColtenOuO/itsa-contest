#include <iostream>
using namespace std;

int p[1001];

int main() {
    int n, t;
    cin >> n >> t;

    for(int i=0;i<n;i++) {
        int id;
        cin >> id;
        p[id]++;
    }

    for(int i=1;i<=1000;i++) {
        if( p[i] >= t ) cout << i << "\n";
    }

    return 0;
}