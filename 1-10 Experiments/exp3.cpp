#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, int>> events;

    for (int i = 0; i < n; i++) {
        long long l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }

    sort(events.begin(), events.end());

    vector<long long> cnt(n + 1, 0);

    long long prev = events[0].first;
    int cur = 0;

    for (auto &e : events) {
        long long x = e.first;
        if (x > prev && cur > 0) {
            cnt[cur] += (x - prev);
        }
        cur += e.second;
        prev = x;
    }

    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << " ";
    }

    return 0;
}