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

const int MOD = 1e9 + 7;

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
    int n;
    cin >> n;

    map<int, vector<int>> people;
    vector<int> kys;

    string curr;
    getline(cin, curr);
    for (int i = 0; i < n; i++)  {
        getline(cin, curr);
        stringstream currLine(curr);

        int x; while (currLine >> x) people[x].push_back(i);
    }

    for (auto &s : people) kys.push_back(s.first);
    debug(people);

    vector<vector<mi>> dp(kys.size(), vector<mi>(1ll << n));
    vector<vector<bool>> visited(kys.size(), vector<bool>((1ll << n), false));

    function<mi(int, int)> recur;
    recur = [&](int tshirt, int bitmask) -> mi{
        debug(tshirt, bitmask);
        if (bitmask == (1ll << n) - 1) return 1;
        if (tshirt == kys.size()) return 0;

        if (visited[tshirt][bitmask]) return dp[tshirt][bitmask];

        mi answer = recur(tshirt + 1, bitmask);
        for (int person : people[kys[tshirt]]) {
            debug(tshirt, person);
            if ((bitmask) & (1ll << person)) continue;
            answer += recur(tshirt + 1, (bitmask | (1ll << person)));
        }
        debug(tshirt, bitmask, (int)answer);

        visited[tshirt][bitmask] = true;
        return dp[tshirt][bitmask] = answer;
    };

    int answer = (int)recur(0, 0);
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

