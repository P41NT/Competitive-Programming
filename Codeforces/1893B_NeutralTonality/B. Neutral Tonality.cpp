#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;

#ifndef ONLINE_JUDGE
#include "/home/shobwq/Compocode/debug.cpp"
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
    int m;
    cin >> m;

    vector<int> arr(n);
    vector<int> brr(m);
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    for (int j = 0; j < m; j++) { cin >> brr[j]; }

    sort(brr.begin(), brr.end(), greater<int>());

    vector<int> answer;

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr[i] >= brr[j]) {
            answer.push_back(arr[i]);
            i++;
        }
        else {
            answer.push_back(brr[j]); 
            j++;
        }
    }

    while (i < n) {
        answer.push_back(arr[i]);
        i++;
    }
    while (j < m) {
        answer.push_back(brr[j]);
        j++;
    }

    for (auto s : answer) {
        cout << s << " ";
    }

    cout << endl;
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

