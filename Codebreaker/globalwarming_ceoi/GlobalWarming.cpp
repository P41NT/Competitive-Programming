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

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> prefLis(n);

    vector<int> lis;
    for (int i = 0; i < n; i++) {
        if (lis.empty() || arr[i] > lis.back()) {
            lis.push_back(arr[i]);
            prefLis[i] = lis.size();
        }
        else {
            int index = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[index] = arr[i];
            prefLis[i] = index + 1;
        }
    }

    int answer = *max_element(prefLis.begin(), prefLis.end());

    vector<int> lds;
    lds.push_back(-arr[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        int index = lower_bound(lds.begin(), lds.end(), -(arr[i] - x)) - lds.begin();
        answer = max(answer, index + prefLis[i]);

        int index2 = lower_bound(lds.begin(), lds.end(), -arr[i]) - lds.begin();
        if (index2 == lds.size()) lds.push_back(-arr[i]);
        else lds[index2] = -arr[i];
    }

    cout << answer << endl;
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

