#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #ifndef ONLINE_JUDGE
// #include "../debug.cpp"
// #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
// #else
#define debug(...)
#define debugArr(...)
// #endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> tempfreq(26, 0);
    for (int i = 0; i < n;i++) {
        tempfreq[s[i] - 'a']++;
    }

    vector<int> freq;

    vector<int> letters;

    for (int i = 0; i < 26; i++) {
        if (tempfreq[i]) {
            freq.push_back(tempfreq[i]);
            letters.push_back(i);
        }
    }
    
    int l = freq.size();
    vector<vector<int>> tempadj(26, vector<int>(26));

    for (int i = 1; i < n; i++) {
        tempadj[s[i] - 'a'][s[i - 1] - 'a']++;
    }

    vector<vector<int>> adj(l, vector<int>(l));

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            adj[i][j] = tempadj[letters[i]][letters[j]];
        }
    }

    debug(letters);
    debug(adj);

    vector<int> dp(1ll << l, 1e12);
    dp[0] = 1;
    for (int bit = 0; bit < (1ll << l); bit++) {
        for (int j = 0; j < l; j++) {
            if (bit & (1ll << j)) {
                int sum = dp[bit ^ (1ll << j)];
                for (int k = 0; k < l; k++) {
                    if (bit & (1ll << k)) {
                        sum += adj[j][k];
                    }
                }

                dp[bit] = min(dp[bit], sum);
            }
        }
    }

    debug(dp);

    cout << dp[(1ll << l) - 1] << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

