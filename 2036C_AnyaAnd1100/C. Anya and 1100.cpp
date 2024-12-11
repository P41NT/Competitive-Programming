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
    
    int q;
    cin >> q;

    int answer = 0;

    for (int i = 0; i + 3 < s.size(); i++) 
        if (s.substr(i, 4) == "1100") answer++;

    debug(answer);

    while (q--) {
        int a; char b;
        cin >> a >> b;
        a--;

        int previous = 0;
        for (int i = a - 3; i <= a; i++) {
            if (i < 0 || i + 3 >= s.size()) continue;
            if (s.substr(i, 4) == "1100") previous++;
        }
        s[a] = b;
        int current = 0;
        for (int i = a - 3; i <= a; i++) {
            if (i < 0 || i + 3 >= s.size()) continue;
            if (s.substr(i, 4) == "1100") current++;
        }

        debug(current, previous);

        int diff = current - previous;
        answer += diff;

        debug(s);
        if (answer > 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
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
