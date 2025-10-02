#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using mi = atcoder::modint1000000007;

const int maxint = 2e5 + 5;
vector<mi> fact(maxint + 1);

void preprocess() {
    fact[0] = fact[1] = 1;

    for (int i = 2; i <= maxint; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }


    if (m != n-1) {
        cout << 0 << endl;
        return;
    }

    debug(degree);

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (auto s : adj[i]) {
            if (degree[s] == 1) continue;
            count++;
        }
        if (count > 2) {
            cout << 0 << endl;
            return;
        }
    }

    mi answer = 2;
    int count2 = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) continue;

        count2++;
        int count = 0;
        for (auto s : adj[i]) {
            if (degree[s] == 1)
                count++;
        }
        answer *= fact[count];
    }
    if (count2 >= 2) answer *= 2;

    cout << answer.val() << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    preprocess();

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

