#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

void solve() {
    int n, k;
    cin >> n >> k;

    int zeroes = k;
    int ones = n - k;

    vector<vector<int>> adj(n + 1);

    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    int mxDepth = n + 1;
    vector<int> depth(n + 1);

    depth[0] = 0;
    depth[1] = 1;

    function<void(int, int)> dfs;
    dfs = [&](int curr, int parent) {
        if (adj[curr].size() == 1 && curr != 1) {
            mxDepth = min(mxDepth, depth[curr]);
        }

        for (auto s : adj[curr]) {
            if (s == parent) continue;
            depth[s] = depth[curr] + 1;
            dfs(s, curr);
        }
    };

    dfs(1, 0);

    vector<int> depthSize(n + 1);
    for (int i = 1; i <= n; i++) {
        depthSize[depth[i]]++;
    }

    debug(depth);
    debug(depthSize);
    debug(mxDepth);

    auto chk = [&](int x) -> bool {
        int t0 = zeroes;
        int t1 = ones;

        for (int i = x; i >= 1; i--) {
            if (t0 > t1) {
                if (depthSize[i] > t0) {
                    return false;
                }
                t0 -= depthSize[i];
            }
            else {
                if (depthSize[i] > t1) {
                    return false;
                }
                t1 -= depthSize[i];
            }
        }

        return true;
    };

    int lower = 1, higher = mxDepth;
    int answer = 1;

    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk(mid)) {
            lower = mid + 1;
            answer = max(answer, mid);
        }
        else {
            higher = mid - 1;
        }
    }

    cout << answer << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

