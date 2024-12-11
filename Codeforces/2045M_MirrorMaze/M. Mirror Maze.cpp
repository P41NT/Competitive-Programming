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
    int n, m;
    cin >> n >> m;

    vector<string> arr(n + 1);
    int mir = 0;
    for (int i = 1; i <= n; i++) {
        string k; cin >> k;
        k = "." + k;
        arr[i] = k;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) { 
            if (arr[i][j] != '.') mir++; 
        }
    }

    debug(mir);

    vector<vector<vector<bool>>> visited(n + 1, vector<vector<bool>>(m + 1, vector<bool>(5)));
    function<bool(int, int, int, int)> dfs;
    dfs = [&](int i, int j, int mirrors, int direction) -> bool {
        debug(i, j, mirrors, direction);
        if (mirrors == 0) return true;
        if (i == 0 || j == 0 || i == n + 1 || j == m + 1) return false;
        if (visited[i][j][direction]) return false;
        visited[i][j][direction] = true;

        // 1 right 2 left 3 down 4 up
        if (arr[i][j] == '\\') {
            if (direction == 1) return dfs(i + 1, j, mirrors - 1, 3);
            if (direction == 2) return dfs(i - 1, j, mirrors - 1, 4);
            if (direction == 3) return dfs(i, j + 1, mirrors - 1, 1);
            if (direction == 4) return dfs(i, j - 1, mirrors - 1, 2);
        }
        if (arr[i][j] == '/') {
            if (direction == 1) return dfs(i - 1, j, mirrors - 1, 4);
            if (direction == 2) return dfs(i + 1, j, mirrors - 1, 3);
            if (direction == 3) return dfs(i, j - 1, mirrors - 1, 2);
            if (direction == 4) return dfs(i, j + 1, mirrors - 1, 1);
        }
        if (direction == 1) return dfs(i, j + 1, mirrors, 1);
        if (direction == 2) return dfs(i, j - 1, mirrors, 2);
        if (direction == 3) return dfs(i + 1, j, mirrors, 3);
        if (direction == 4) return dfs(i - 1, j, mirrors, 4);
        return 0;
    };

    vector<string> answer;

    for (int i = 1; i <= m; i++) {
        if (dfs(1, i, mir, 3)) answer.push_back("N" + to_string(i));
        debug("something");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= 4; k++)
                    visited[i][j][k] = false;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dfs(i, m, mir, 2)) answer.push_back("E" + to_string(i));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= 4; k++) 
                    visited[i][j][k] = false;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dfs(i, 1, mir, 1)) answer.push_back("W" + to_string(i));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= 4; k++) 
                    visited[i][j][k] = false;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (dfs(n, i, mir, 4)) answer.push_back("S" + to_string(i));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 1; k <= 4; k++) 
                    visited[i][j][k] = false;
            }
        }
    }

    cout << answer.size() << endl;
    for (auto s : answer) cout << s << " ";
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

