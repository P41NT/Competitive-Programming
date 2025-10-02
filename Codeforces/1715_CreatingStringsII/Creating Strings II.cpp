#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/modint.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using mint = atcoder::modint1000000007;

const int maxn = 1e6;
vector<mint> fact(maxn + 5);

void preprocess() {
    fact[0] = 1, fact[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void solve() {
    string s;
    cin >> s;

    vector<int> freq(26);
    for (auto ch : s) freq[ch - 'a']++;

    mint ans = (mint)fact[s.length()];
    for (int i = 0; i < 26; i++) {
        ans /= fact[freq[i]];
    }

    cout << ans.val() << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    preprocess();
    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

