#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    unordered_map<int, vector<int>> pos;
    for (int i = 1; i <= n; i++) {
        pos[a[i]].push_back(i);
    }

    vector<int> nxt(n + 2, n + 1);

    for (auto &p : pos) {
        auto &v = p.second;
        int sz = v.size();
        for (int i = 0; i < sz; i++) {
            if (i + k < sz) nxt[v[i]] = v[i + k];
            else nxt[v[i]] = n + 1;
        }
    }

    int LOG = 20;
    vector<vector<int>> jump(LOG, vector<int>(n + 2));

    for (int i = 1; i <= n + 1; i++) jump[0][i] = nxt[i];

    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n + 1; i++) {
            jump[j][i] = jump[j - 1][jump[j - 1][i]];
        }
    }

    int q;
    cin >> q;

    int last = 0;

    while (q--) {
        int x, y;
        cin >> x >> y;

        int l = ((x + last) % n) + 1;
        int r = ((y + last) % n) + 1;
        if (l > r) swap(l, r);

        int cur = l;
        int ans = 0;

        for (int j = LOG - 1; j >= 0; j--) {
            if (jump[j][cur] <= r) {
                ans += (1 << j);
                cur = jump[j][cur];
            }
        }

        if (cur <= r) ans++;

        cout << ans << '\n';
        last = ans;
    }

    return 0;
}