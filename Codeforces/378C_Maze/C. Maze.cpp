#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

const int MOD = 998244353;

struct mi {
	int v;
	explicit operator int() const { return v; }
	mi() { v = 0; }
	mi(long long _v) : v(_v % MOD) { v += (v < 0) * MOD; }
};
mi &operator+=(mi &a, mi b) {
	if ((a.v += b.v) >= MOD) a.v -= MOD;
	return a;
}
mi &operator-=(mi &a, mi b) {
	if ((a.v -= b.v) < 0) a.v += MOD;
	return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi &operator*=(mi &a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
	assert(p >= 0);
	return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) {
	assert(a.v != 0);
	return pow(a, MOD - 2);
}
mi operator/(mi a, mi b) { return a * inv(b); }

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> arr(n, vector<char>(m));

    pair<int, int> start;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == '.')
                start = {i, j};
        }
    }


    debug(start);
    queue<pair<int, int>> bfs;
    bfs.push(start);
    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[start.first][start.second] = true;

    int dir_x[] = {-1, 0, 1, 0};
    int dir_y[] = {0, -1, 0, 1};
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[start.first][start.second] = 0;

    while (!bfs.empty()) {
        auto [i, j] = bfs.front();
        bfs.pop();
        for (int k = 0; k < 4; k++) {
            int nexti = i + dir_x[k];
            int nextj = j + dir_y[k];
            
            if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) continue;
            if (visited[nexti][nextj]) continue;
            if (arr[nexti][nextj] == '#') continue;

            visited[nexti][nextj] = true;
            dist[nexti][nextj] = dist[i][j] + 1;
            bfs.push({nexti, nextj});
        }
    }

    debug(dist);
    vector<pair<int, pair<int, int>>> points;

    for (int i = 0; i < n;i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] != -1) {
                points.push_back({dist[i][j], {i, j}});
            }
        }
    }

    sort(points.begin(), points.end(), greater<pair<int, pair<int, int>>>());

    for (int i = 0; i < k; i++) 
        arr[points[i].second.first][points[i].second.second] = 'X';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << arr[i][j];
        cout << endl;
    }
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    solve();
}

