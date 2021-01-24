/**
 *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
 *
 *  author  :   prodipdatta7
 *  created :   Saturday 23-May, 2020  12:22:02 AM
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

const int N          = (int)1e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}

/*...... ! Code starts from here ! ......*/

int Log[N] ; 

void build_log(){
	Log[1] = 0 ;
	for(int i = 2 ; i < N ; ++i){
		Log[i] = Log[i / 2] + 1 ;
	}
}

struct TRIE {
    int node[26], n = 0, LogN = 0 ; 
    vector < int > ind, val ; 
    vector < vector < int > > table ; 
    TRIE() {
        for(int i = 0 ; i < 26 ; ++i)
 			node[i] = -1 ; 
 		ind.clear() ; 
 		val.clear() ; 
 		table.clear() ; 
    }

    int build(){
    	n = sz(val) ; 
    	LogN = Log[n] ; 
    	table.assign(n, vector < int > (LogN + 1, 0)) ; 
    	for(int i = 0 ; i < n ; ++i)
    		table[i][0] = val[i] ; 
    	for(int j = 1 ; j <= LogN ; ++j){
    		for(int i = 0 ; i + (1 << j) <= n ; ++i)
    			table[i][j] = max(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]) ;
    	}
    }

    int query(int l, int r){
    	int x = Log[r - l + 1] ; 
    	return max(table[l][x], table[r - (1 << x) + 1][x]) ; 
    }
} ;

// T.assign(1, TRIE()) ; //
// include in main //

vector < TRIE > T ; 
int a[N] ; 

void add(string s, int id, int val) {
    int v = 0, n = sz(s) ; 
    for (int i = 0 ; i < n ; ++i) {
        int bit = s[i] - 'a' ;
        if (T[v].node[bit] == -1)T[v].node[bit] = sz(T), T.pb(TRIE()) ;
        v = T[v].node[bit] ;
        T[v].ind.push_back(id) ; 
        T[v].val.push_back(val) ; 
    }
}

void build(int s){
	T[s].build() ; 
	for(int i = 0 ; i < 26 ; ++i){
		if(T[s].node[i] != -1)build(T[s].node[i]) ; 
	}
}

ll query(string s, int L, int R) {
    int v = 0, n = sz(s) ;
    ll res = 0 ;
    for(int i = 0 ; i < n ; ++i){
    	int p = s[i] - 'a' ;
    	if(T[v].node[p] == -1)break ; 
    	v = T[v].node[p] ; 
    	int r = upper_bound(all(T[v].ind), R) - T[v].ind.begin() - 1 ; 
    	int l = lower_bound(all(T[v].ind), L) - T[v].ind.begin() ; 
    	if(r < l)break ; 
    	res = max(res, 1LL * T[v].query(l, r) * (i + 1)) ;
    	//error(l, r, s, L, R, i, res)
    }
    return res ;
}

void solve(){
	int n ; Int(n) ; 
	T.assign(1, TRIE()) ; 
	for(int i = 0 ; i < n ; ++i){
		Int(a[i]) ; 
        assert(a[i] >= 1 and a[i] <= 1000000) ; 
    }
	string s ; 
	for(int i = 0 ; i < n ; ++i){
		cin >> s ; 
        for(int j = 0 ; s[j] ; ++j)
            assert(s[j] >= 'a' and s[j] <= 'z') ; 
		add(s, i, a[i]) ; 
	}
	build_log() ; 
	build(0) ; 
	int q, l, r ; Int(q) ; 
	while(q--){
		cin >> s >> l >> r ; 
        assert(l >= 1 and l <= n) ; 
        assert(r >= 1 and r <= n) ; 
        assert(l <= r) ; 
		ll res = query(s, l - 1, r - 1) ; 
		cout << res << '\n' ; 
	}
}

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("17.in", "r", stdin) ;
    freopen("17.out", "w", stdout) ;
#endif

    int test = 1 , tc = 0 ;
    //Int(test) ;
    while (test--) {
    	solve() ; 
    }

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0 ;
}