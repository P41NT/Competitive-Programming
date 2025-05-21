#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/Compocode/debug.cpp"
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

    auto query = [&](int x, int y) -> int {
        cout << "? " << x << " " << y << endl;
        cout.flush();
        int a; cin >> a;
        return a;
    };

    vector<int> parent(n);

    queue<int> q;
    q.push(n - 1);
    int par = n - 2;
    while (par && q.size()) {
        int curr = q.front();
        if (curr == 1 || par == 0) break;
        int qq = query(curr, par);
        if (qq == 0) {
            parent[curr] = par;
            q.pop();
        }
        q.push(par);
        if (qq == 1 && par == 1) {
            break;
        }
        par--;
    }

    cout << "! ";
    for (int i = 1; i < n; i++) cout << parent[i] << " ";
    cout << endl;
    cout.flush();
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

