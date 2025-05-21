#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

// #ifndef ONLINE_JUDGE
// #include "/home/shobwq/CompetitiveProgramming/debug.cpp"
// #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
// #else
// #define debug(...)
// #define debugArr(...)
// #endif

#define endl "\n"
#define int long long int

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].second >> arr[i].first;

    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    int answer = 0;
    while (i < j) {
        answer = max(answer, arr[i].first + arr[j].first);
        if (arr[i].second > arr[j].second) {
            arr[i].second -= arr[j].second;
            arr[j].second = 0, j--;
        }
        else if (arr[i].second < arr[j].second) {
            arr[j].second -= arr[i].second;
            arr[i].second = 0, i++;
        }
        else {
            arr[i].second = 0, arr[j].second = 0;
            i++, j--;
        }
    }

    cout << answer << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

