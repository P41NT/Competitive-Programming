#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<int> indA(26, -1);
    vector<int> indB(26, -1);

    for (int i = 1; i < n; i++) {
        if (indA[a[i] - 'a'] == -1)
            indA[a[i] - 'a'] = i;
    }
    for (int i = 0; i < m - 1; i++) {
        debug(b[i] - 'a');
        indB[b[i] - 'a'] = i;
    }

    debug(indA);
    debug(indB);

    int len = -1;
    string ans = "";
    for (int c = 0; c < 26; c++) {
        if (indA[c] != -1 && indB[c] != -1) {
            string answer = a.substr(0, indA[c]) + b.substr(indB[c]);
            if (len == -1 || answer.size() < len) {
                len = answer.size();
                ans = answer;
            }
        }
    }
    if (len == -1) {
        cout << -1 << endl;
        return;
    }
    cout << ans << endl;;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

