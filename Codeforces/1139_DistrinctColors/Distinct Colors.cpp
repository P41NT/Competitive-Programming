#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#include <atcoder/segtree.hpp>

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

set<int> op(set<int> a, set<int> b) {
    set<int> c = a;
    c.merge(b);
    return c;
}

set<int> e() {
    set<int> t;
    return t;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    vector<int> color(n + 1);
    for (int i = 1; i <= n; i++) { cin >> color[i]; }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> start(n + 1);
    vector<int> end(n + 1);

    vector<int> euler;

    int time = 0;
    function<void(int, int)> dfs;
    dfs = [&](int curr, int parent) {
        start[curr] = time++;
        euler.push_back(curr);
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            dfs(s, curr);
        }
        end[curr] = time;
    };

    dfs(1, -1);

    vector<int> eulerColor(euler.size());
    for (int i = 0; i < euler.size(); i++) eulerColor[i] = color[euler[i]];

    atcoder::segtree<set<int>, op, e> segs(euler.size());
    for (int i = 0; i < euler.size(); i++) {
        segs.set(i, {eulerColor[i]});
    }

    for (int i = 1; i <= n; i++) {
        int left = start[i];
        int right = end[i];
        debug(left, right);
        int ans = segs.prod(left, right).size();

        cout << ans << " ";
    }
    cout << endl;
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

