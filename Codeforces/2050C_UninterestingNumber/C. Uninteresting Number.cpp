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
    string s;
    cin >> s;

    int sm = 0;
    int twofreq = 0;
    int threefreq = 0;
    for (int i = 0; i < s.size(); i++) { 
        sm += s[i] - '0'; 
        if (s[i] == '2') twofreq++;
        if (s[i] == '3') threefreq++;
    }

    debug(s, sm);

    if (sm % 9 == 0) {
        cout << "YES" << endl;
        return;
    }
    int required = 9 - (sm % 9);

    debug(sm);
    debug(required);
    
    vector<int> index = {0, 5, 1, 6, 2, 7, 3, 8, 4, 9};
    int ind = index[required];

    vector<int> possible(10, false);
    for (int i = 0; i <= twofreq; i++) {
        for (int j = 0; j <= threefreq && i + 3 * j <= 9; j++) {
            possible[i + 3 * j] = true;
        }
    }
    debug(twofreq, threefreq, possible);

    if (possible[ind]) {cout << "YES" << endl;}
    else cout << "NO" << endl;
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

