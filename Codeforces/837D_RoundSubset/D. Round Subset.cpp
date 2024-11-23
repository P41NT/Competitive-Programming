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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 222;

const int maxP = 6000;
const int maxP2 = 12000;

int dp[2][maxn][maxP2];
int twos[maxn];
int fives[maxn];
int arr[maxn];

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n;i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int x = arr[i];
        while (!(x % 5)) {
            fives[i]++;
            x /= 5;
        }
        while (!(x & 1)) {
            twos[i]++;
            x >>=1;
        }
    }

    // vector<vector<map<int, int>>> dp(n + 1, vector<map<int, int>>(k + 1));
    

    // vector<vector<unordered_map<int, int>>> dp(n + 1, vector<unordered_map<int, int>> (k + 1));
    // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (k + 1, vector<int>(maxP * 2, -1)));
    // vector<vector<vector<int>>> dp(2, vector<vector<int>>(k + 1, vector<int>(maxP2, 0)));
    // vector<vector<int>> newdp(k + 1, vector<int>(maxP * 2 + 1, 0));
    k++;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j < k; j++) {
            for (int p = 0; p < maxP2; p++) {
                p -= maxP;
                int nd = twos[i] - fives[i], s = min(twos[i], fives[i]), pr = p + nd;

                if ((p < 0) != (nd < 0)) s += min(abs(p), abs(nd));
                pr += maxP;
                if (pr < 0) pr = 0;
                if (pr >= maxP2) pr = maxP2 - 1;

                p += maxP;
                dp[i&1][j][p] = max(dp[!(i&1)][j][p], dp[!(i&1)][j - 1][pr] + s);
            }
        }
    }
    
    cout << dp[0][k - 1][maxP] << endl;
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


