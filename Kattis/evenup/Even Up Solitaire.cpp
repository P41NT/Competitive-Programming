#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

void solve() {
    int n;
    cin >> n;
    stack<int> st;
    int k;
    while (n--) {
        cin >> k;
        if(st.size() == 0) st.push(k);
        else if(st.top()%2 == k%2) st.pop();
        else st.push(k);
    }

    cout << st.size() << endl;
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

