#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> cnt(n + 1, 0);
        for (int x : a) cnt[x]++;

        vector<int> good(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int sum = a[i];
            for (int j = i + 1; j < n; j++) {
                sum += a[j];
                if (sum > n) break;
                good[sum] = 1;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (good[i]) ans += cnt[i];
        }

        cout << ans << '\n';
    }

    return 0;
}