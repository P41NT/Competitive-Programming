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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    //
    // if (arr.size() == 0) {
    //     assert(n == 1);
    //     int c2 = n * (n + 1) / 2;
    //     cout << 1 << " ";
    //     for (int i = 1; i < n; i++) {
    //         cout << 0 << " ";
    //     }
    //     cout << endl;
    //     return;
    // }
    //
    // debug(arr);
    //
    // n = arr.size();

    vector<int> tempkeys(n);
    set<int> st;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) continue;

        int t = abs(arr[i]);
        int key = 1;
        for (int p = 2; p * p <= t; p++) {
            int counter = 0;
            while (t % p == 0) {
                t /= p;
                counter ^= 1;
            }
            if (counter) key *= p;
        }
        if (t > 1) key *= t;
        if (arr[i] < 0) key *= -1;

        tempkeys[i] = key;
        st.insert(key);
    }

    map<int, int> mp;
    int counter = 1;
    for (auto s : st) {
        mp[s] = counter++;
    }

    vector<int> keys(n);
    for (int i = 0; i < n; i++) {
        keys[i] = mp[tempkeys[i]];
    }

    debug(keys);

    vector<int> answer(n + 1);

    for (int i = 0; i < n; i++) {
        vector<bool> visited(counter);
        int curr_counter = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] != 0 && !visited[keys[j]]) {
                curr_counter++;
                visited[keys[j]] = true;
            }
            answer[max(1ll, curr_counter)]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
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

