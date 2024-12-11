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

    vector<vector<char>> arr(n, vector<char>(m));
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ;j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'S') start = {i, j};
            if (arr[i][j] == 'T') end = {i, j};
        }
    }

    int dir_x[] = {-1, 0, 1, 0};
    int dir_y[] = {0, -1, 0, 1};

    const int inf = 1e18;

    // int visited[100][100][5][5];
    // for (int i = 0; i < 100; i++) {
    //     for (int j = 0; j < 100; j++) {
    //         for (int k = 0; k < 5; k++) {
    //             for (int l = 0; l < 5; l++) 
    //                 visited[i][j][k][l] = inf;
    //         }
    //     }
    // }
    vector<vector<array<array<int, 5>, 5>>> 
        visited(n, vector<array<array<int, 5>, 5>>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 5; k++) {
                for (int l = 0; l < 5; l++) 
                    visited[i][j][k][l] = inf;
            }
        }
    }

    // vector<vector<int>>(n, vector<int>(m)) visited[5][5];

    // array<array<vector<vector<int>>, 5>, 5> visited;

    debug(end);

    struct node { int i; int j; int curr; int dir; };
    queue<node> bfs;

    bfs.push({start.first, start.second, 3, 4});
    visited[start.first][start.second][3][4] = 0;

    while (!bfs.empty()) {
        auto [i, j, curr, dir] = bfs.front();
        bfs.pop();

        debug(i, j, curr, dir);
        
        if (curr == 0) continue;

        for (int k = 0; k < 4; k++) {
            int nexti = i + dir_x[k];
            int nextj = j + dir_y[k];

            if (nexti >= n || nexti < 0 || nextj >= m || nextj < 0) continue;
            if (arr[nexti][nextj] == '#') continue;

            int nextcurr = dir == k ? curr - 1 : 3;
            if (nextcurr == 0) continue;
            if (visited[nexti][nextj][nextcurr][k] != inf) continue;

            // answer = min(answer, self(self, nexti, nextj, (dir == k) ? curr - 1 : 3, k));
        
            visited[nexti][nextj][nextcurr][k] = visited[i][j][curr][dir] + 1;
            bfs.push({nexti, nextj, nextcurr,  k});
            // if (dir == k) answer = min(answer, self(self, nexti, nextj, curr - 1, k));
            // else answer = min(answer, self(self, nexti, nextj, 4, k));
        }
    }


    int ans = inf;
    for (int i = 0; i <= 4; i++) {
        for (int j = 0; j <= 4; j++) {
            ans = min(ans, visited[end.first][end.second][i][j]);
        }
    }
    // int ans = dfs(dfs, start.first, start.second, 4, -1);
    if (ans == inf) ans = -1;
    cout << ans << endl;
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

