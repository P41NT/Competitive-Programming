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
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> sz(n + 1);

    function<int(int, int)> dfs;
    dfs = [&](int curr, int parent) -> int {
        int currAns = 0;
        sz[curr] = 1;
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            currAns += dfs(s, curr);
            currAns += (arr[curr] ^ arr[s]) * sz[s];

            sz[curr] += sz[s];
        }
        debug(curr, currAns);
        return currAns;
    };

    int answer = dfs(1, 0);
    debug(sz);

    vector<int> finalanswer(n + 1);
    finalanswer[1] = answer;

    function<void(int, int)> reroot;
    reroot = [&](int curr, int parent) {
        int currAns = finalanswer[parent]
            - (arr[curr] ^ arr[parent]) * sz[curr] 
            + (arr[curr] ^ arr[parent]) * (n - sz[curr]);

        debug(finalanswer[parent], arr[curr] ^ arr[parent]);
        debug(sz[curr], n - sz[curr]);

        finalanswer[curr] = currAns;

        for (auto s : adj[curr]) {
            if (s == parent) continue;
            reroot(s, curr);
        }
    };

    for (auto s : adj[1]) reroot(s, 1);

    for (int i = 1; i <= n; i++) cout << finalanswer[i] << " ";
    cout << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

