#include <bits/stdc++.h>

namespace __DEBUG_UTIL__
{
    /* Primitive Datatypes Print */
    void print(const char *x) { std::cerr << x; }
    void print(bool x) { std::cerr << (x ? "T" : "F"); }
    void print(char x) { std::cerr << '\'' << x << '\''; }
    void print(signed short int x) { std::cerr << x; }
    void print(unsigned short int x) { std::cerr << x; }
    void print(signed int x) { std::cerr << x; }
    void print(unsigned int x) { std::cerr << x; }
    void print(signed long int x) { std::cerr << x; }
    void print(unsigned long int x) { std::cerr << x; }
    void print(signed long long int x) { std::cerr << x; }
    void print(unsigned long long int x) { std::cerr << x; }
    void print(float x) { std::cerr << x; }
    void print(double x) { std::cerr << x; }
    void print(long double x) { std::cerr << x; }
    void print(std::string x) { std::cerr << '\"' << x << '\"'; }
    template <size_t N>
    void print(std::bitset<N> x) { std::cerr << x; }
    void print(std::vector<bool> v)
    { /* Overloaded this because stl optimizes vector<bool> by using
          _Bit_reference instead of bool to conserve space. */
        int f = 0;
        std::cerr << '{';
        for (auto &&i : v)
            std::cerr << (f++ ? "," : "") << (i ? "T" : "F");
        std::cerr << "}";
    }
    /* Templates Declarations to support nested datatypes */
    template <typename T>
    void print(T &&x);
    template <typename T>
    void print(std::vector<std::vector<T>> mat);
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M]);
    template <typename F, typename S>
    void print(std::pair<F, S> x);
    template <typename T, size_t N>
    struct Tuple;
    template <typename T>
    struct Tuple<T, 1>;
    template <typename... Args>
    void print(std::tuple<Args...> t);
    template <typename... T>
    void print(std::priority_queue<T...> pq);
    template <typename T>
    void print(std::stack<T> st);
    template <typename T>
    void print(std::queue<T> q);
    /* Template Datatypes Definitions */
    template <typename T>
    void print(T &&x)
    {
        /*  This works for every container that supports range-based loop
            i.e. vector, set, map, oset, omap, dequeue */
        int f = 0;
        std::cerr << '{';
        for (auto &&i : x)
            std::cerr << (f++ ? "," : ""), print(i);
        std::cerr << "}";
    }
    template <typename T>
    void print(std::vector<std::vector<T>> mat)
    {
        int f = 0;
        std::cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            std::cerr << std::setw(2) << std::left << f++, print(i), std::cerr << "\n";
        }
        std::cerr << "~~~~~\n";
    }
    template <typename T, size_t N, size_t M>
    void print(T (&mat)[N][M])
    {
        int f = 0;
        std::cerr << "\n~~~~~\n";
        for (auto &&i : mat)
        {
            std::cerr << std::setw(2) << std::left << f++, print(i), std::cerr << "\n";
        }
        std::cerr << "~~~~~\n";
    }
    template <typename F, typename S>
    void print(std::pair<F, S> x)
    {
        std::cerr << '(';
        print(x.first);
        std::cerr << ',';
        print(x.second);
        std::cerr << ')';
    }
    template <typename T, size_t N>
    struct Tuple
    {
        static void printTuple(T t)
        {
            Tuple<T, N - 1>::printTuple(t);
            std::cerr << ",", print(std::get<N - 1>(t));
        }
    };
    template <typename T>
    struct Tuple<T, 1>
    {
        static void printTuple(T t) { print(std::get<0>(t)); }
    };
    template <typename... Args>
    void print(std::tuple<Args...> t)
    {
        std::cerr << "(";
        Tuple<decltype(t), sizeof...(Args)>::printTuple(t);
        std::cerr << ")";
    }
    template <typename... T>
    void print(std::priority_queue<T...> pq)
    {
        int f = 0;
        std::cerr << '{';
        while (!pq.empty())
            std::cerr << (f++ ? "," : ""), print(pq.top()), pq.pop();
        std::cerr << "}";
    }
    template <typename T>
    void print(std::stack<T> st)
    {
        int f = 0;
        std::cerr << '{';
        while (!st.empty())
            std::cerr << (f++ ? "," : ""), print(st.top()), st.pop();
        std::cerr << "}";
    }
    template <typename T>
    void print(std::queue<T> q)
    {
        int f = 0;
        std::cerr << '{';
        while (!q.empty())
            std::cerr << (f++ ? "," : ""), print(q.front()), q.pop();
        std::cerr << "}";
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
        std::cerr.write(names, i) << " = ";
        print(head);
        if (sizeof...(tail))
            std::cerr << " ||", printer(names + i + 1, tail...);
        else
            std::cerr << "]\n";
    }
    /* PrinterArr */
    void printerArr(const char *) {} /* Base Recursive */
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t ind = 0;
        for (; names[ind] and names[ind] != ','; ind++)
            std::cerr << names[ind];
        for (ind++; names[ind] and names[ind] != ','; ind++)
            ;
        std::cerr << " = {";
        for (size_t i = 0; i < N; i++)
            std::cerr << (i ? "," : ""), print(arr[i]);
        std::cerr << "}";
        if (sizeof...(tail))
            std::cerr << " ||", printerArr(names + ind + 1, tail...);
        else
            std::cerr << "]\n";
    }
}

