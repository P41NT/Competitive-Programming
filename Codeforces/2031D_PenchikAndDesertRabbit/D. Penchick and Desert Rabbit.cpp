#include <algorithm>
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

    debug(arr);

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) pref[i] = max(pref[i - 1], arr[i]);
    vector<int> suff(n + 1);
    suff[n] = arr[n];
    for (int i = n - 1; i >= 1; i--) suff[i] = min(suff[i + 1], arr[i]);

    debug(pref);
    debug(suff);

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        if (pref[i] > suff[i + 1]) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
    }

    debug(adj);

    vector<int> answer(n + 1);

    vector<int> visited(n + 1);
    function<int(int)> getMax;
    vector<int> visited2(n + 1);
    function<void(int, int)> fillMax;

    getMax = [&](int curr) -> int {
        debug(curr);
        visited[curr] = true;
        int mx = arr[curr];
        for (auto s : adj[curr]) {
            if (visited[s]) continue;
            mx = max(mx, getMax(s));
        }
        return mx;
    };

    fillMax = [&](int curr, int mx) {
        visited2[curr] = true;
        answer[curr] = mx;

        for (auto s : adj[curr]) {
            if (visited2[s]) continue;
            fillMax(s, mx);
        }
    };

    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        int mx = getMax(i);
        fillMax(i, mx);
    }


    for (int i = 1; i <= n; i++) cout << answer[i] << " ";
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

