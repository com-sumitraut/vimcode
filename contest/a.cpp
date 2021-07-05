#include <bits/stdc++.h>

#define speedup ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr),cout.precision(12)
using namespace std;
using ll=long long;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    ll a[n][m], ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            if (i != 0) a[i][j] += a[i - 1][j];
            if (j != 0) a[i][j] += a[i][j - 1];
            if (i != 0 && j != 0) a[i][j] -= a[i - 1][j - 1];
            int l = 0, r = min(i, j) + 1;
            while (l < r) {
                int md = (l + r) >> 1;
                int I = i - md - 1;
                int J = j - md - 1;
                ll sum = a[i][j];
                if (I >= 0) sum -= a[I][j];
                if (J >= 0) sum -= a[i][J];
                if (I >= 0 && J >= 0) sum += a[I][J];
                if (sum >= k * (md+1) * (md+1)) l = md + 1;
                else r = md;
            }
            ans += l;
        }
    }
    cout << ans << '\n';
}

int main() {
    speedup;
    int t;
    cin >> t;
    while (t--)
        solve();
}


