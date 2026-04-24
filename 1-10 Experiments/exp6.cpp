#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<string> st;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        st.insert(s);
    }

    while (m--) {
        cin >> s;
        bool ok = false;

        for (int i = 0; i < (int)s.size() && !ok; i++) {
            char orig = s[i];
            for (char c : {'a', 'b', 'c'}) {
                if (c == orig) continue;
                s[i] = c;
                if (st.count(s)) {
                    ok = true;
                    break;
                }
            }
            s[i] = orig;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}