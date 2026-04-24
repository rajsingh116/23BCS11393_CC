#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> v;
    string s;
    while (cin >> s) v.push_back(s);

    int i = 0;
    function<string()> solve = [&]() -> string {
        if (i >= v.size()) return "";
        if (v[i] == "int") {
            i++;
            return "int";
        }
        i++;
        string left = solve();
        if (left == "") return "";
        string right = solve();
        if (right == "") return "";
        return "pair<" + left + "," + right + ">";
    };

    string ans = solve();
    if (i != v.size() || ans == "") cout << "Error occurred";
    else cout << ans;

    return 0;
}