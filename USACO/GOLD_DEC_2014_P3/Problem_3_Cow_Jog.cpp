#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
    int n, t;
    cin >> n >> t;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int x, s;
        cin >> x >> s;
        arr[i] = x + s * t;
    }

    reverse(arr.begin(), arr.end());
    // sort(arr.begin(), arr.end(), greater<int>());

    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int index = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (index == dp.size()) dp.push_back(arr[i]);
        else dp[index] = arr[i];
    }

    cout << dp.size() << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

