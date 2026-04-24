#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& h, long long target) {
    long long odd = 0, even = 0;
    for (auto x : h) {
        long long d = target - x;
        odd += d % 2;
        even += d / 2;
    }

    if (odd > even) {
        return 2 * odd - 1;
    } else {
        long long rem = even - odd;
        return 2 * odd + (rem / 3) * 2 + (rem % 3);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> h(n);
        long long mx = 0;

        for (int i = 0; i < n; i++) {
            cin >> h[i];
            mx = max(mx, h[i]);
        }

        long long ans = min(solve(h, mx), solve(h, mx + 1));
        cout << ans << '\n';
    }

    return 0;
}