#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifdef SHAWN
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
    int n, m;
    cin >> n >> m;

    pair<int, int> start1;
    pair<int, int> start2;
    
    cin >> start1.first >> start1.second;
    cin >> start2.first >> start2.second;

    vector<pair<int, int>> pos1(1, start1);
    vector<pair<int, int>> pos2(1, start2);

    string path1, path2;
    cin >> path1 >> path2;

    for (int i = 0; i < n; i++) {
        auto next = pos1.back();
        if (path1[i] == 'N') next.second++;
        if (path1[i] == 'S') next.second--;
        if (path1[i] == 'E') next.first++;
        if (path1[i] == 'W') next.first--;

        pos1.push_back(next);
    }

    for (int i = 0; i < m; i++) {
        auto next = pos2.back();
        if (path2[i] == 'N') next.second++;
        if (path2[i] == 'S') next.second--;
        if (path2[i] == 'E') next.first++;
        if (path2[i] == 'W') next.first--;

        pos2.push_back(next);
    }

    auto dist2 = [&](pair<int, int> a, pair<int, int> b) {
        return  (a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second);
    };

    debug(pos1);
    debug(pos2);

    const int inf = 1e10;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int j) -> int {
        if (i > n || j > m) return inf;
        if (i == n && j == m) return dp[i][j] = dist2(pos1[i], pos2[j]);

        if (dp[i][j] != -1) return dp[i][j];

        int answer = dist2(pos1[i], pos2[j]);
        int nextanswer = inf;
        nextanswer = min(nextanswer, recur(i + 1, j));
        nextanswer = min(nextanswer, recur(i, j + 1));
        nextanswer = min(nextanswer, recur(i + 1, j + 1));

        if (nextanswer == inf) return inf;
        return dp[i][j] = answer + nextanswer;
    };


    int answer = min(recur(1, 0), recur(0, 1));
    answer = min(answer, recur(1, 1));
    debug(dp);
    // int answer = recur(0, 0);
    cout << answer << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

