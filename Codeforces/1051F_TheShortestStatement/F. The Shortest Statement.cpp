#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <atcoder/dsu.hpp>
#include <atcoder/segtree.hpp>

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

const int inf = 1e12;

void dijkstra(int source, vector<int> &dist, vector<vector<pair<int, int>>> &adj) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, source});

    dist.resize(adj.size(), inf);

    dist[source] = 0;
    while (!pq.empty()) {
        auto [d, curr] = pq.top();
        pq.pop();
        if (-d != dist[curr]) continue;

        for (auto [s, weight] : adj[curr]) {
            if (dist[curr] + weight < dist[s]) {
                dist[s] = dist[curr] + weight;
                pq.push({-dist[s], s});
            }
        }
    }
}

class LCA {
    int n;
    vector<int> height, euler, first;

    struct segNode {
        int node;
        int depth;
    };
    static segNode op(segNode a, segNode b) {
        return (a.depth < b.depth) ? a : b;
    }
    static segNode e() {
        return segNode{(int)1e12, (int)1e12};
    }

    atcoder::segtree<segNode, op, e> segs;

    void dfs(vector<vector<int>> &adj, int curr, int parent, int h) {
        height[curr] = h;
        first[curr] = euler.size();
        euler.push_back(curr);
        for (auto s : adj[curr]) {
            if (s == parent) continue;
            dfs(adj, s, curr, h + 1);
            euler.push_back(curr);
        }
    }

public:
    LCA(vector<vector<int>> &adj, int root) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        // debug(adj);
        dfs(adj, root, -1, 0);
        int m = euler.size();
        segs = atcoder::segtree<segNode, op, e>(m);
        for (int i = 0; i < m; i++) {
            segs.set(i, {euler[i], height[euler[i]]});
        }
    }

    int lca(int u, int v) {
        int left = first[u];
        int right = first[v];
        if (left > right) swap(left, right);
        return segs.prod(left, right + 1).node;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    // take edges to compute MST
    vector<pair<int, pair<int, int>>> edges;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});

        edges.push_back({c, {a, b}});
    }

    sort(edges.begin(), edges.end());

    // mst with weight for dijkstra
    // mst without weight for lca
    vector<vector<pair<int, int>>> mst(n + 1);
    vector<vector<int>> mstWeightless(n + 1);

    // stores extra nodes (the nodes that were part of the extra edges not included in mst)
    set<int> extrasSet;

    // make MST with kahns algorithm
    atcoder::dsu d(n + 1);
    for (auto [w, p] : edges) {
        auto [a, b] = p;
        if (d.same(a, b)) {
            extrasSet.insert(a);
            extrasSet.insert(b);
            continue;
        }
        d.merge(a, b);
        mst[a].push_back({b, w});
        mst[b].push_back({a, w});
        mstWeightless[a].push_back(b);
        mstWeightless[b].push_back(a);
    }

    vector<int> extras;
    for (auto s : extrasSet) extras.push_back(s);

    debug(mst);
    debug(extras);

    // store shortest paths from extra nodes to all other nodes
    vector<vector<int>> dijk(extras.size());
    for (int i = 0; i < extras.size(); i++) { dijkstra(extras[i], dijk[i], adj); }

    debug(dijk);

    // compute lowest common ancestor for MST
    LCA lca(mstWeightless, 1);

    // debug("lca done");

    // calculate distance from root for all nodes in MST
    vector<int> rootDist;
    dijkstra(1, rootDist, mst);

    debug(rootDist);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        // calculate length with MST
        int l = lca.lca(a, b);
        int mstLength = rootDist[a] + rootDist[b] - 2 * rootDist[l];
        debug(a, b, mstLength);

        // calculate length with extra nodes dijkstra
        int dijkLength = 1e12;
        int dijkNode = -1;
        for (int i = 0; i < dijk.size(); i++) {
            // compute length from node to a + node to b
            int curr = dijk[i][a] + dijk[i][b];
            if (curr < dijkLength) {
                dijkLength = curr;
                dijkNode = extras[i];
            }
        }
        debug(dijkLength);
        debug(dijkNode);

        cout << min(mstLength, dijkLength) << endl;
    }
    // this is gonna be a pain in the ass to debug T_T
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
	while (t--) {
        solve();
	}
}

