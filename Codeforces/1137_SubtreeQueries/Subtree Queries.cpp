#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/segtree.hpp>

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

    function<void(int, int)> dfs;
    int time = 1;
    dfs = [&](int curr, int parent) {
        start[curr] = time++;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            dfs(s, curr);
        }
        end[curr] = time;
    };

    dfs(1, 0);

    vector<int> prog(n + 1);
    for (int i = 1; i <= n; i++) { prog[start[i]] = arr[i]; }

    atcoder::segtree<int, op, e> segs(prog);

    while (q--) {
        // for (int i = 0; i <= n; i++) cerr << segs.get(i) << " ";
        // cerr << endl;
        int op; cin >> op;
        if (op == 1) {
            int s; int x;
            cin >> s >> x;
            segs.set(start[s], x);
        }
        else {
            int p; cin >> p;
            debug(start[p], end[p]);
            int answer = segs.prod(start[p], end[p]);
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

