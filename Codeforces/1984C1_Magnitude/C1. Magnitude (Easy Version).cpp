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
    int n;
    cin >> n;

    vector<int> arr(n + 2);
    vector<int> pref(n + 2);
    vector<int> suff(n + 2);
    
    for (int i = 1; i <= n; i++) { cin >> arr[i]; }
    for (int i = 1; i <= n; i++) { pref[i] = pref[i - 1] + arr[i]; }
    for (int i = n; i >= 1; i--) { suff[i] = suff[i + 1] + arr[i]; }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int curr = abs(pref[i - 1] + arr[i]);
        curr += suff[i + 1];
        answer = max(answer, curr);
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

