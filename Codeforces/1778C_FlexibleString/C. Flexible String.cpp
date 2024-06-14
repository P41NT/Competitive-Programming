#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, k;
    cin >> n >> k;

    string a;
    cin >> a;
    string b;
    cin >> b;

    set<char> temp;
    for(int i = 0; i < n; i++) temp.insert(a[i]);
    vector<char> arr;
    for (auto s : temp) 
        arr.push_back(s);

    k = min(k, (int)arr.size());

    vector<bool> good(n, false);
    int ans = 0;
    for (int i = 0; i < (1ll << (arr.size())); i++) {
        if (__builtin_popcount(i) != k)  continue;

        // for (int j = 0; j < arr.size(); j++) 
        //     cerr << (((1ll << j) & i) > 0);
        // cerr << endl;

        for (int k = 0; k < n; k++)
            good[k] = (a[k] == b[k]);

        for (int j = 0; j < arr.size(); j++) {
            if ((1ll << j) & i) {
                for (int k = 0; k < n; k++)
                    good[k] = good[k] || (a[k] == arr[j]);
            }
        }

        int curr_ans = 0;
        int cnt = 0;
        for (int j = 0; j <= n; j++) {
            if (j == n || !good[j]) curr_ans += (cnt*(cnt-1)/2 + cnt), cnt = 0;
            else cnt++;
        }
        ans = max(ans, curr_ans);
    }
    
    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

