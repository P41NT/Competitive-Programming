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

    vector<string> arr(n);

    for (int i = 0; i < n;i ++) { cin >> arr[i]; }

    vector<vector<int>> status(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m));

    int dir_x[] = {1, 0, -1, 0};
    int dir_y[] = {0, 1, 0, -1};

    function<int(int, int)> dfs;
    dfs = [&](int i, int j) -> int {
        visited[i][j] = 1;
        char next = arr[i][j];
        int k = -1;
        switch(next) {
            case 'U': k = 2; break;
            case 'D': k = 0; break;
            case 'R': k = 1; break;
            case 'L': k = 3; break;
        }

        if (k == -1) {
            visited[i][j] = 2;
            return status[i][j] = 0;
        }

        int nexti = i + dir_x[k];
        int nextj = j + dir_y[k];

        if (nexti >= n || nextj >= m || nexti < 0 || nextj < 0) {
            visited[i][j] = 2;
            return status[i][j] = 1;
        }

        if (visited[nexti][nextj] == 2) {
            visited[i][j] = 2;
            return status[i][j] = status[nexti][nextj];
        }

        if (visited[nexti][nextj] == 1) {
            visited[i][j] = 2;
            return status[i][j] = -1;
        }

        int req = dfs(nexti, nextj);
        visited[i][j] = 2;
        return status[i][j] = req;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] != '?' && visited[i][j] == 0) dfs(i, j);
        }
    }

    debug(status);

    int answer = n * m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (status[i][j] == 0) {
                bool get = true;
                for (int k = 0; k < 4; k++) {
                    int nexti = i + dir_x[k];
                    int nextj = j + dir_y[k];

                    if (nexti >= n || nextj >= m || nexti < 0 || nextj < 0) continue;
                    if (status[nexti][nextj] == 1) continue;
                    get = false;
                }
                debug(i, j, get);
                if (get) answer--;
            }
            else if (status[i][j] == 1) answer--;
        }
    }

    cout << answer << endl;
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

