#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int k = a + b;
    int sum = 0;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >>c[i];
    for (int i = 0; i < n; i++){
        int k; cin >> k;
        c[i] = abs(c[i] - k);
        sum += c[i];
    }

    priority_queue<int> pq;
    for (auto s : c) pq.push(s);

    while (k--) {
        int curr = pq.top();
        pq.pop();
        curr--; 
        pq.push(abs(curr));
    }

    int ans = 0;
    while (!pq.empty()){
        ans += pq.top() * pq.top();
        pq.pop();
    }
    cout << ans << endl;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t = 1;
	// cin >> t;
	while ( t-- ) {
		solve();
	}
}

