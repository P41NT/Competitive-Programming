#include <algorithm>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "../debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// lazy_segtree<S, op, e, F, mapping, composition, id> seg(int n);

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> front;
    for (int i = 1; i <= n; i++) {
        if (front.empty() || front.back() < arr[i]) {
            front.push_back(arr[i]);
        }
    }

    vector<int> back;
    for (int i = n; i >= 1; i--) {
        if (back.empty() || back.back() < arr[i]) {
            back.push_back(arr[i]);
        }
    }

    back.pop_back();
    while (back.size()) {
        front.push_back(back.back());
        back.pop_back();
    }

    int mxInd = max_element(front.begin(), front.end()) - front.begin();

    debug(front);


    int m = front.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 2, -1));

    function<int(int, int)> recur;
    recur = [&](int i, int j) -> int {
        if (i == m) return dp[i][j] = 1;
        if (j == n + 1) return dp[i][j] = 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (i <= mxInd) {
            if (i != 0 && arr[j] <= front[i - 1]) {
                return dp[i][j] = 2 * recur(i, j + 1);
            }
            else if (front[i] == arr[j]) {
                return dp[i][j] = recur(i + 1, j + 1) + recur(i, j + 1);
            }
            else {
                return dp[i][j] = recur(i, j + 1);
            }
        }
        else {
            if (i - 1 == mxInd) {
                if (arr[j] == front[i - 1]) {
                    return dp[i][j] = 2 * recur(i, j + 1);
                }
            }
            if (arr[j] == front[i]){
                return dp[i][j] = recur(i + 1, j + 1) + recur(i, j + 1);
            }
            else if (arr[j] < front[i]) {
                return dp[i][j] = 2 * recur(i, j + 1);
            }
            else {
                return dp[i][j] = recur(i, j + 1);
            }
        }
    };


    int answer = recur(0, 0);
    debug(dp);

    cout << answer << endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

