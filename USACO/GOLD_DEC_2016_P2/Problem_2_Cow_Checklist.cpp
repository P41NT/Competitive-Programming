#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #ifndef ONLINE_JUDGE
// #include "/home/shobwq/CompetitiveProgramming/debug.cpp"
// #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
// #define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
// #else
// #define debug(...)
// #define debugArr(...)
// #endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int h, g;
    cin >> h >> g;

    vector<pair<int, int>> arr(h + 1);
    vector<pair<int, int>> brr(g + 1);

    for (int i = 1; i <= h; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 1; i <= g; i++) cin >> brr[i].first >> brr[i].second;

    auto dist2 = [&](pair<int, int> a, pair<int, int> b) {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    };

    // int dp[h + 1][g + 1][2];

    vector<vector<vector<int>>> dp(h + 1, vector<vector<int>>(g + 1, vector<int>(2, -1)));
    
    // for (int i = 0; i <= h; i++) {
    //     for (int j = 0; j <= g; j++) {
    //         for (int k = 0; k < 2; k++) dp[i][j][k] = -1;
    //     }
    // }
    
    const int inf = 1e10;

    function<int(int, int, int)> recur;
    recur = [&](int currh, int currg, int last) -> int {
        pair<int, int> position = (last ? brr[currg] : arr[currh]);
        // debug(position);
        if (currh == h && currg == g) {
            if (last) return inf;
            return 0;
        }

        if (dp[currh][currg][last] != -1) return dp[currh][currg][last];

        int answer = INT_MAX;
        if (currh < h) {
            auto next = arr[currh + 1];
            int currans = recur(currh + 1, currg, 0) + dist2(position, next);
            answer = min(answer, currans);
        }
        if (currg < g) {
            auto next = brr[currg + 1];
            int currans = recur(currh, currg + 1, 1) + dist2(position, next);
            answer = min(answer, currans);
        }
        // debug(position, answer);
        return dp[currh][currg][last] = answer;
    };


    int answer = recur(1, 0, 0);

    cout << answer << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

