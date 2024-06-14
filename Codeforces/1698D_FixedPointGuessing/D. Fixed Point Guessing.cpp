#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define int long long int

int k;
int n;

void process_query(int left, int right) {
    if (left == right) {
        cout << "! " << left << endl;
        cout.flush();
        return;
    }

    if (left >= right) return;
    int half = (right + left) >> 1;
    cout << "? " << left << " " << half << endl;
    cout.flush();

    int correct = 0;
    for (int i = 1; i <= (half - left + 1); i++) {
        cin >> k;
        if (k >= left && k <= half) correct++;
    }

    if (correct & 1) process_query(left, half);
    else process_query(half + 1, right);
}

void solve() {
    cin >> n;
    process_query(1, n);
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 

	int t = 1;
	cin >> t;
	while ( t-- ) {
		solve();
	}
}

