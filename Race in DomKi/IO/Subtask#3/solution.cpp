/**
     *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
     *
     *  author  :   Prodip Datta
     *  handle  :   prodipdatta7
     *  created :   Monday 03-August, 2020  05:47:01 PM
**/

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

using namespace std ;
using namespace __gnu_pbds ;

#define     ll          long long
#define     ld          long double
#define     ull         unsigned long long
#define     pii         pair<int,int>
#define     pll         pair<ll,ll>
#define     vi          vector<int>
#define     vll         vector<ll>
#define     vvi         vector<vector<int>>
#define     debug(x)    cerr << #x << " = " << x << '\n' ;
#define     rep(i,b,e)  for(__typeof(e) i = (b) ; i != (e + 1) - 2 * ((b) > (e))  ; i += 1 - 2 * ((b) > (e)))
#define     all(x)      x.begin() , x.end()
#define     rall(x)     x.rbegin() , x.rend()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#define     fread       freopen("input.txt","r",stdin)
#define     fwrite      freopen("output.txt","w",stdout)
#define     TN          typename
#define     FastIO      ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;

/*
Note :  There is a problem with erase() function in ordered_multiset (for less_equal<int> tag).
        lower_bound() works as upper_bound() and vice-versa.
        Be careful to use.
        i) find_by_order(k) : kth smallest element counting from 0 .
        ii) order_of_key(k) : number of elements strictly smaller than k.
*/

/*###############-> Input Section <-###############*/

template <TN T> inline void Int(T &a) {
    bool minus = false; a = 0; char ch = getchar();
    while (true) { if (ch == '-' or (ch >= '0' && ch <= '9')) break; ch = getchar(); }
    if (ch == '-') minus = true; else a = ch - '0';
    while (true) { ch = getchar(); if (ch < '0' || ch > '9') break; a = a * 10 + (ch - '0'); }
    if (minus)a *= -1 ;
}
template < TN T, TN T1 > inline void Int(T &a, T1 &b) {Int(a), Int(b) ;}
template < TN T, TN T1, TN T2 > inline void Int(T &a, T1 &b, T2 &c) {Int(a, b), Int(c) ;}
template < TN T, TN T1, TN T2, TN T3 > inline void Int(T &a, T1 &b, T2 &c, T3 &d) {Int(a, b), Int(c, d) ;}
template < TN T, TN T1, TN T2, TN T3, TN T4> inline void Int(T &a, T1 &b, T2 &c, T3 &d, T4 &e) {Int(a, b), Int(c, d, e) ;}

/*###############-> Debugger <-###############*/

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<TN T, TN... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}
#else
#define error(args...)
#endif

template<class ValueType>
bool unstable_remove(
    typename std::vector<ValueType>& container,
    typename std::vector<ValueType>::iterator it
) {
    auto lastEl = container.end() - 1;
    if (it != lastEl) {
        *it = std::move(*lastEl);
    }
    container.pop_back();
}

/******************************************
#Rows are numbered from top to bottom.
#Columns are numbered from left to right.
Moves : L, U, R, D, LU, RU, RD, LD.
******************************************/
int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1} ;
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1} ;

/*###############-> Constraints <-###############*/

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const double EPS     = (double)1e-9 ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}

/*...... ! Code starts from here ! ......*/

vector < vector < int > > g ;
int v[N], par[N][20], dep[N] ;
int UpHash[2][N], DownHash[2][N], mod[2] = {(int)1e9 + 7, (int)1e9 + 9}, pw[2][N] ;
ll mask[N] ;
int base[2] = {67, 159} ;

void GeneratePower() {
    pw[0][0] = pw[1][0] =  1 ;
    for (int i = 1 ; i < N ; ++i) {
        for (int j = 0 ; j < 2 ; ++j)
            pw[j][i] = mul(pw[j][i - 1], base[j], mod[j]) ;
    }
}

void dfs(int s, int p) {
    par[s][0] = p ;
    mask[s] ^= (1LL << v[s]) ;
    mask[s] ^= mask[p] ;
    for (int i = 1 ; i < 20 ; ++i)
        par[s][i] = par[par[s][i - 1]][i - 1] ;
    for (int i = 0 ; i < 2 ; ++i) {
        UpHash[i][s] = add(v[s], mul(base[i], UpHash[i][p], mod[i]), mod[i]) ;
        DownHash[i][s] = add(DownHash[i][p], mul(v[s], pw[i][dep[s]], mod[i]), mod[i]) ;
    }
    for (int i : g[s]) {
        if (i == p)continue ;
        dep[i] = 1 + dep[s] ;
        dfs(i, s) ;
    }
}

int LCA(int a, int b) {
    if (dep[a] < dep[b])swap(a, b) ;
    int d = dep[a] - dep[b] ;
    for (int i = 19 ; i >= 0 ; --i)
        if (d >> i & 1)a = par[a][i] ;
    if (a == b)return a ;
    for (int i = 19 ; i >= 0 ; --i)
        if (par[a][i] != par[b][i])
            a = par[a][i], b = par[b][i] ;
    return par[a][0] ;
}

bool Type1(int a, int b) {
    int anc = LCA(a, b) ;
    ll bitmask = 0 ;
    bitmask = mask[a] ^ mask[anc] ;
    bitmask ^= (mask[b] ^ mask[par[anc][0]]) ;
    return __builtin_popcountll(bitmask) <= 1 ;
}

template < typename T, typename T1, typename T2> inline T modpow(T b, T1 p, T2 mod) {
    T res = 1 ;
    if (b >= mod)b %= mod ;
    while (p > 0) {
        if (p & 1)res = mul(res, b, mod) ;
        b = mul(b, b, mod) ;
        p >>= 1 ;
    }
    return res ;
}

int subTask(int i, int a, int b, int anc) {
    int lenA = dep[a] - dep[anc] ;
    int L = sub(UpHash[i][a], mul(pw[i][lenA], UpHash[i][anc], mod[i]), mod[i]) ;
    int R = sub(DownHash[i][b], DownHash[i][par[anc][0]], mod[i]) ;
    lenA -= dep[anc] ;
    if (!lenA) {
        return add(L, R, mod[i]) ;
    }
    else {
        int p ;
        if (lenA < 0) {
            lenA *= -1;
            p = modpow(pw[i][lenA], mod[i] - 2, mod[i]) ;
        }
        else p = pw[i][lenA] ;
        R = mul(R, p, mod[i]) ;
        return add(L, R, mod[i]) ;
    }
}

bool Type2(int a, int b) {
    int anc = LCA(a, b) ;
    int x = subTask(0, a, b, anc) ;
    int y = subTask(0, b, a, anc) ;
    return (x == y) and (subTask(1, a, b, anc) == subTask(1, b, a, anc)) ;
}

bool Type3(int a, int b, int c, int d) {
    int anc1 = LCA(a, b) ;
    int anc2 = LCA(c, d) ;
    int len1 = dep[a] + dep[b] - 2 * dep[anc1] + 1 ;
    int len2 = dep[c] + dep[d] - 2 * dep[anc2] + 1 ;
    return (len1 == len2) and (subTask(0, a, b, anc1) == subTask(0, c, d, anc2)) and (subTask(1, a, b, anc1) == subTask(1, c, d, anc2)) ;
}

void clr(int n){
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j < 20 ; ++j)
            par[i][j] = 0 ; 
        v[i] = 0 ; 
        mask[i] = 0 ; 
        UpHash[0][i] = UpHash[1][i] = 0 ;
        DownHash[0][i] = DownHash[1][i] = 0 ;
        dep[i] = 0 ;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("1.in", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;
#endif

    int test = 1 , tc = 0 ;
    Int(test) ;
    while (test--) {
        int n ; Int(n) ;
        g.assign(n + 1, vector < int > ()) ;
        for (int i = 1 ; i <= n ; ++i)
            Int(v[i]) ;
        for (int i = 1 ; i < n ; ++i) {
            int x, y ; Int(x, y) ;
            g[x].push_back(y) ;
            g[y].push_back(x) ;
        }
        GeneratePower() ;
        dfs(1, 0) ;
        printf("Case %d:\n",++tc);
        int q ; Int(q) ;
        int tp, a, b, c, d ;
        while (q--) {
            Int(tp, a, b) ;
            if (tp == 1)puts(Type1(a, b) ? "YES" : "NO") ;
            else if (tp == 2)puts(Type2(a, b) ? "YES" : "NO") ;
            else {
                Int(c, d) ;
                puts(Type3(a, b, c, d) ? "YES" : "NO") ;
            }
        }
        clr(n) ; 
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0 ;
}