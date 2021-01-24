/**
 *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
 *
 *  author  :   prodipdatta7
 *  created :   Saturday 23-May, 2020  11:15:01 PM
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


int a[N], T1[N << 2], n ; 
ll T2[N << 2] ; 
map< int, int > F ; 

void update(int i, int b, int e, int p, int f, int v){
	if(p < b or p > e)return ; 
	if(b == e){
		T1[i] += f ; 
		T2[i] += v ; 
		return ; 
	}
	int mid = b + e >> 1 ; 
	update(i << 1, b, mid, p, f, v) ; 
	update(i << 1 | 1, mid + 1, e, p, f, v) ; 
	T1[i] = T1[i << 1] + T1[i << 1 | 1] ; 
	T2[i] = T2[i << 1] + T2[i << 1 | 1] ; 
}

int query(int i, int b, int e, ll v){
	if(b == e)return T2[i] <= v and T1[i] > 0 ;
	int mid = b + e >> 1 ; 
	if(T2[i << 1] <= v)return T1[i << 1] + query(i << 1 | 1, mid + 1, e, v - T2[i << 1]) ; 
	else return query(i << 1 , b, mid, v) ; 
}


const int block = 400 ;

struct Query{
    int l, r, id ;
    ll k ; 
    Query():l(0),r(0), k(0), id(0){}
    Query(int l, int r, ll k, int id):l(l), r(r), k(k), id(id){}
    bool operator<(const Query &p)const{
        return make_pair(l / block, r) < make_pair(p.l / block, p.r) ;
    }
}Q[N] ;

bool cmp(Query &a, Query &b){
    if(a.l / block != b.l / block)return a < b ;
    return ((a.l / block) & 1) ? a.r < b.r : a.r > b.r ;
}

void insert(int x){
	update(1, 1, n, F[x], 1, x) ; 
	--F[x] ; 
}

void remove(int x){
	++F[x] ; 
	update(1, 1, n, F[x], -1, -x) ;
}

void Run_MO(int q) {
    sort(Q + 1 , Q + q + 1, cmp) ;
    int l = 1, r = 0 ;
    vi ans(q + 1) ;
    for (int i = 1 ; i <= q ; ++i) {
    	while (r < Q[i].r)insert(a[++r]) ;		while (l > Q[i].l)insert(a[--l]) ;
        while (l < Q[i].l)remove(a[l++]) ;		while (r > Q[i].r)remove(a[r--]) ;
        //error(T1[1], T2[1])
        ans[Q[i].id] = query(1, 1, n, Q[i].k) ; 
    }
    for (int i = 1 ; i <= q ; ++i)
        printf("%d\n", ans[i]);
}

void solve(){
	Int(n) ; 
	vector < int > val ; 
	for(int i = 1 ; i <= n ; ++i){
		Int(a[i]) ; 
		val.push_back(a[i]) ; 
		F[a[i]]++ ; 
	}
	sort(all(val)) ;
	val.erase(unique(all(val)), val.end()) ;
	for(int i = 1 ; i < sz(val) ; ++i){
		F[val[i]] += F[val[i - 1]] ;
	}
	int q ; Int(q) ; 
	for(int i = 1 ; i <= q ; ++i){
		int l, r ; 
		ll k ; 
		Int(l, r, k) ; 
		Q[i] = Query(l, r, k, i) ;
	}
	Run_MO(q) ; 
}

int main() {
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("6.in", "r", stdin) ;
    freopen("6.out", "w", stdout) ;
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