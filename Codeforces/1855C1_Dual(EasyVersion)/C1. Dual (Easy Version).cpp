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
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<pair<int, int>> answer;

    int mxind = max_element(arr.begin(), arr.end()) - arr.begin();

    if (arr[mxind] <= 0) {
        for (int i = n - 1; i > 0; i--) {
            debug(arr);
            if (arr[i - 1] > arr[i]) {
                arr[i - 1] += arr[i];
                answer.push_back({i, i + 1});
            }
        }
        debug(arr);

        cout << answer.size() << endl;
        for (auto s : answer) cout << s.first << " "<< s.second << endl;
        return;
    }

    while (arr[mxind] <= 20) {
        arr[mxind] += arr[mxind];
        answer.push_back({mxind + 1, mxind + 1});
    }

    for (int i = 1; i < n; i++) {
        while (arr[i] < arr[i - 1]) {
            arr[i] += arr[mxind];
            answer.push_back({i + 1, mxind + 1});
            if (arr[i] > arr[mxind]) mxind = i;
        }
    }

    debug(arr);

    cout << answer.size() << endl;
    for (auto s : answer) cout << s.first << " " << s.second << endl;
    return;
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

