#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/CompetitiveProgramming/debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;

    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> pref(n + 2);
    vector<int> suff(n + 2);
    int counter = 0;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += arr[i];
        if (sum >= v) counter++, sum = 0;
        pref[i] = counter;
    }

    sum = 0;
    counter = 0;
    for (int i = n; i >= 1; i--) {
        sum += arr[i];
        if (sum >= v) counter++, sum = 0;
        suff[i] = counter;
    }

    debug(pref);
    debug(suff);

    int i = 1, j = 0;
    int curr = 0;
    int answer = -1;
    while (i <= n && j <= n) {
        int right = suff[j + 1];
        int left = pref[i - 1];

        int feed = right + left;
        if (feed >= m) {
            debug(i, j, feed, curr);
            answer = max(answer, curr);
            j++;
            curr += arr[j];
        }
        else curr -= arr[i], i++;
        if (i > j + 1) j++, curr += arr[j];
    }

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

