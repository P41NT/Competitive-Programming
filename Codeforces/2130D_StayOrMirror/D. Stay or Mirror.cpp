#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#include "debug.cpp"
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define int long long int

template<class T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n; cin >> n;
  vector<int> vec(n);
  vector<int> pref(n), suff(n);
  int cnt = 0;
 
  {
    ordered_set<int> s;
    for (int i = 0; i < n; ++i) {
      cin >> vec[i];
      pref[i] = s.order_of_key(-vec[i]);
      cnt += pref[i];
      s.insert(-vec[i]);
    }
  }
 
  {
    ordered_set<int> s;
    for (int i = n - 1; i >= 0; --i) {
      suff[i] = s.order_of_key(-vec[i]);
      s.insert(-vec[i]);
    }
  }
  debug(pref, suff);
  for(int a=0 ; a<n ; a+=1){
    cnt -= max(0ll , pref[a] - suff[a]);
  }
  cout<<cnt<<endl;
}

int32_t main () {
    std::ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    cin >> t;
	while (t--) {
        solve();
	}
}

