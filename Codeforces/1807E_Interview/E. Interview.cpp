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

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) arr[i].second = i + 1;

    sort(arr.begin(), arr.end());
    debug(arr);

    vector<int> pref(n);
    pref[0]= arr[0].first;

    for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + arr[i].first;

    auto qu = [&](vector<int> &q) -> int {
        cout << "? " << q.size() << " ";
        for (auto s : q) cout << s << " ";
        cout << endl;
        cout.flush();
        
        int answer;
        cin >> answer;
        return answer;
    };

    auto chk = [&](int mid) -> bool{
        vector<int> query;
        int sm = 0;
        for (int i = 0; i < mid; i++) {
            query.push_back(arr[i].second);
            sm += arr[i].first;
        }
        int actual = qu(query);

        return actual > sm;
    };

    int lower = 1, higher = n;
    int answer = n;
    while (lower <= higher) {
        int mid = (lower + higher) >> 1;
        if (chk(mid)) {
            higher = mid - 1;
            answer = min(answer, mid);
        }
        else { lower = mid + 1; }
    }
    cout << "! " << arr[answer - 1].second << endl;
    cout.flush();
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

