#include <atcoder/segtree.hpp>
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

int op(int a, int b) { return a + b; }
int e() { return 0ll; }

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> start(n + 1);
    vector<int> end(n + 1);

    int time = 1;

    function<void(int, int)> dfs;
    dfs = [&](int curr, int parent) {
        start[curr] = time++;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            dfs(s, curr);
        }
        end[curr] = time++;
    };

    dfs(1, 0);

    vector<int> p(2 * n + 1);
    for (int i = 1; i <= n; i++) p[start[i]] = arr[i];
    for (int i = 1; i <= n; i++) p[end[i]] = -arr[i];

    atcoder::segtree<int, op, e> segs(p);

    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int s, x;
            cin >> s >> x;
            segs.set(start[s], x);
            segs.set(end[s], -x);
        }
        else {
            int x;
            cin >> x;
            int answer = segs.prod(0, start[x] + 1);
            cout << answer << endl;
        }
    }
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

