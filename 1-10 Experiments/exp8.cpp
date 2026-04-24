#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });

    vector<double> prefA(n + 1, 0), prefB(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefA[i + 1] = prefA[i] + a[order[i]];
        prefB[i + 1] = prefB[i] + b[order[i]];
    }

    double totalB = prefB[n];

    cout << fixed << setprecision(10);

    for (int k = 1; k <= n; k++) {
        double cap = prefA[k];
        double inside = prefB[k];
        double outside = totalB - inside;

        double ans = min(cap, inside + outside / 2.0);
        cout << ans << " ";
    }

    return 0;
}