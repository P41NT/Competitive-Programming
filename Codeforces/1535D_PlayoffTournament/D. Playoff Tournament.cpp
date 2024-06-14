#include <bits/stdc++.h>

using namespace std;

namespace __DEBUG_UTIL__
{
    using namespace std;
    /* Primitive Datatypes Print */
    void print(const char *x) { cerr << x; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(char x) { cerr << '\'' << x << '\''; }
    void print(signed short int x) { cerr << x; }
    void print(unsigned short int x) { cerr << x; }
    void print(signed int x) { cerr << x; }
    void print(unsigned int x) { cerr << x; }
    void print(signed long int x) { cerr << x; }
    void print(unsigned long int x) { cerr << x; }
    void print(signed long long int x) { cerr << x; }
    void print(unsigned long long int x) { cerr << x; }
    void print(float x) { cerr << x; }
    void print(double x) { cerr << x; }
    void print(long double x) { cerr << x; }
    void print(string x) { cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(bitset<N> x) { cerr << x; }
    void print(vector<bool> v)
    { /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(vector<vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(tuple<Args...> t);
    template <typename... T>
    void print(priority_queue<T...> pq);
    template <typename T>
    void print(stack<T> st);
    template <typename T>
    void print(queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        cerr << '{';
        for (auto &&i : x)
            cerr << (f++ ? "," : ""), print(i);
        cerr << "}";
    }
    template <typename T>
    void print(vector<vector<T>> mat)
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            cerr << setw(2) << left << f++, print(i), cerr << "\n";
        }
        cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(pair<F, S> x)
    {
        cerr << '(';
        print(x.first);
        cerr << ',';
        print(x.second);
        cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            cerr << ",", print(get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(get<0>(t)); }
    };
    template <typename... Args>
    void print(tuple<Args...> t)
    {
        cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        cerr << ")";
    }
    template <typename... T>
    void print(priority_queue<T...> pq)
    {
        int f = 0;
        cerr << '{';
        while (!pq.empty())
            cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        cerr << "}";
    }
    template <typename T>
    void print(stack<T> st)
    {
        int f = 0;
        cerr << '{';
        while (!st.empty())
            cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        cerr << "}";
    }
    template <typename T>
    void print(queue<T> q)
    {
        int f = 0;
        cerr << '{';
        while (!q.empty())
            cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        cerr << "}";
    }
    /* Printer functions */
    void printer(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        /* Using && to capture both lvalues and rvalues */
        int i = 0;
        for (size_t bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket != 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        if (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    /* PrinterArr */
    void printerArr(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t ind = 0;
        for (; names[ind] and names[ind] != ','; ind++)
            cerr << names[ind];
        for (ind++; names[ind] and names[ind] != ','; ind++)
            ;
        cerr << " = {";
        for (size_t i = 0; i < N; i++)
            cerr << (i ? "," : ""), print(arr[i]);
        cerr << "}";
        if (sizeof...(tail))
            cerr << " ||", printerArr(names + ind + 1, tail...);
        else
            cerr << "]\n";
    }
}
#ifndef ONLINE_JUDGE
#define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif

#define endl "\n"

struct node{
    int index;
    int l, r, parent;
    int ans;
    int val;
};

void genTree(int prev_levelbegin, int levelbegin, int level, vector<node> &tree) {
    if (level < 0) return;

    int levelsize = 1LL << level;
    for (int i = 0; i < levelsize; i++) {
        tree[levelbegin + i].l = prev_levelbegin + 2 * i;
        tree[levelbegin + i].r = prev_levelbegin + 2 * i + 1;
        tree[prev_levelbegin + 2 * i].parent = levelbegin + i;
        tree[prev_levelbegin + 2 * i + 1].parent = levelbegin + i;
    }

    genTree(levelbegin, levelbegin + levelsize, level - 1, tree);
}

void calc_init(int i, vector<node> &tree) {
    if (tree[i].l == -1) {
        switch(tree[i].val) {
            case 0: tree[i].ans = 1; break;
            case 1: tree[i].ans = 1; break;
            case 2: tree[i].ans = 2; break;
        }
        return;
    }

    calc_init(tree[i].l, tree);
    calc_init(tree[i].r, tree);

    switch(tree[i].val) {
        case 0: tree[i].ans = tree[tree[i].l].ans; break;
        case 1: tree[i].ans = tree[tree[i].r].ans; break;
        case 2: tree[i].ans = tree[tree[i].l].ans + tree[tree[i].r].ans; break;
    }
}

void update(int i, vector<node> &tree, int new_val = -1) {
    if (new_val != -1) 
        tree[i].val = new_val;

    if (tree[i].l == -1) {
        switch(tree[i].val) {
            case 0: tree[i].ans = 1; break;
            case 1: tree[i].ans = 1; break;
            case 2: tree[i].ans = 2; break;
        }
    }
    else {
        switch(tree[i].val) {
            case 0: tree[i].ans = tree[tree[i].l].ans; break;
            case 1: tree[i].ans = tree[tree[i].r].ans; break;
            case 2: tree[i].ans = tree[tree[i].l].ans + tree[tree[i].r].ans; break;
        }
    }

    if (tree[i].parent == -1) return;
    update(tree[i].parent, tree, -1);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int m = 1ll << n;

    vector<node> tree(m - 1);
    for (int i = 0; i < m - 1; i++) {
        tree[i].val = (s[i] == '?' ? 2 : s[i] - '0');
        tree[i].index = i;
        tree[i].l = tree[i].r = tree[i].parent = -1;
    }

    genTree(0, (m >> 1), n - 2, tree);
    calc_init(m - 2, tree);

    int q;
    cin >> q;
    while (q--) {
        int r; char tmp;
        cin >> r >> tmp;
        r--;
        int q = (tmp == '?' ? 2 : tmp - '0');
        update(r, tree, q);
        cout << tree[m - 2].ans << endl;
    }
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

