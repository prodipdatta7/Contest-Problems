/**
     *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
     *
     *  author  :   Prodip Datta
     *  handle  :   prodipdatta7
     *  created :   Wednesday 12-August, 2020  08:04:44 AM
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

const int N          = (int)1e3 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}

/*...... ! Code starts from here ! ......*/

ll cell[N][N], mx[N][N], Q[2][N] ; 

void maxify(int m, int k, ll mx[], ll p[], ll q[]) {
	deque < pair < ll, int >  > LMX, RMX ;
	for (int i = 1 ; i <= m ; ++i) {
		//assert(i - j + 1 == k) ;
		while (!LMX.empty() and LMX.back().ff < p[i])LMX.pop_back() ;
		while (!LMX.empty() and i - LMX.front().ss >= k)LMX.pop_front() ;
		LMX.push_back(make_pair(p[i], i)) ;
		if (i - k >= 0)mx[i - k + 1] = LMX.front().ff ;
	}
	for (int i = m ; i >= 1 ; --i) {
		while (!RMX.empty() and RMX.back().ff < q[i])RMX.pop_back() ;
		while (!RMX.empty() and RMX.front().ss - i >= k)RMX.pop_front() ;
		
		RMX.push_back(make_pair(q[i], i)) ;
		if (i + k - 1 <= m)mx[i + k - 1] = max(mx[i + k - 1], 1LL * RMX.front().ff);
	}
	// error(k)	
	// for(int i = 1 ; i <= m ; ++i)
	// 	cout << p[i] << " \n"[i == m] ; 
	// for(int i = 1 ; i <= m ; ++i)
	// 	cout << q[i] << " \n"[i == m] ; 
	// for(int i = 1 ; i <= m ; ++i)
	// 	cout << mx[i] << " \n"[i == m] ; 
	// cout << '\n' ; 
	// cout << '\n' ; 
}

// struct SparseTable {
// 	const static int K = 18 ;
// 	vector < vector < ll > > T ;
// 	vector < int > Log ;
// 	int n ;
// 	SparseTable(int n = 0): n(n) {
// 		T.resize(n, vector < ll > (K)) ;
// 		Log.resize(n + 1, 0) ;
// 		for (int i = 2 ; i <= n ; ++i)
// 			Log[i] = Log[i >> 1] + 1 ;
// 	}
// 	void init(int v) {
// 		T.assign(n, vector < ll > (K, v)) ;
// 	}
// 	void build_max(ll a[]) {
// 		for (int i = 0 ; i < n ; ++i) {
// 			T[i][0] = a[i + 1] ;
// 		}
// 		for (int j = 1 ; j < K ; ++j) {
// 			for (int i = 0 ; i + (1 << j) <= n ; ++i) {
// 				T[i][j] = max(T[i][j - 1], T[i + (1 << (j - 1))][j - 1]) ;
// 			}
// 		}
// 	}

// 	ll query(int l, int r, bool mx) {
// 		int x = Log[r - l + 1] ;
// 		ll a = T[l][x], b = T[r - (1 << x) + 1][x] ;
// 		return mx ? max(a, b) : min(a, b) ;
// 	}
// } ;


void call(int pos, int m, int k, ll mx[]) {
	ll p[m + 1], q[m + 2] ;
	mem(p) ;
	mem(q) ;
	for (int i = 1, j = m ; i <= m ; ++i, --j) {
		p[i] = p[i - 1] + cell[pos][i] ;
		q[j] = q[j + 1] + cell[pos][j] ;
	}
	// SparseTable x(m), y(m) ;
	// x.init(0) ;
	// y.init(0) ;
	for (int i = m, j = 1 ; i >= 1 ; --i, ++j) {
		p[i] = p[i] - ((i < k) ? 0 : p[i - k]) ;
		q[j] = q[j] - ((j + k - 1 > m) ? 0 : q[j + k]) ;
	}
	// x.build_max(p) ;
	// y.build_max(q) ;
	// for (int i = 1 ; i <= m ; ++i) {
	// 	int L = max(1, i - k + 1) ;
	// 	int R = min(m, i + k - 1) ;
	// 	mx[i] = max(y.query(L - 1, i - 1, 1), x.query(i - 1, R - 1, 1)) ;
	// }
	maxify(m, k, mx, p, q) ; 

}

struct SegmentTree {
	vector < ll > T ;
	int n ;
	SegmentTree(int n = 0) : n(n) {
		T.assign(4 * n + 5, 0) ;
	}

	void build(int i, int b, int e, ll a[]) {
		if (b == e) {
			T[i] = a[b] ;
			return ;
		}
		int mid = b + e >> 1 ;
		build(i << 1, b, mid, a) ;
		build(i << 1 | 1, mid + 1, e, a) ;
		T[i] = max(T[i << 1], T[i << 1 | 1]) ;
	}
	void update(int i, int b, int e, int p, int v) {
		if (p < b or p > e)return ;
		if (b == e) {
			T[i] = v ;
			return ;
		}
		int mid = b + e >> 1 ;
		update(i << 1, b, mid, p, v) ;
		update(i << 1 | 1, mid + 1, e, p, v) ;
		T[i] = max(T[i << 1], T[i << 1 | 1]) ;
	}
	ll query(int i, int b, int e, int l, int r) {
		if (r < b or e < l)return 0 ;
		if (l <= b and e <= r)return T[i] ;
		int mid = b + e >> 1 ;
		ll X = query(i << 1, b, mid, l, r) ;
		ll Y = query(i << 1 | 1, mid + 1, e, l, r) ;
		return max(X, Y) ;
	}
} ;

vector < SegmentTree > DS ;

int main() {
#ifndef ONLINE_JUDGE
	clock_t tStart = clock();
	//freopen("input.txt", "r", stdin) ;
	//freopen("output.txt", "w", stdout) ;
#endif

	int test = 1 , tc = 0 ;
	Int(test) ;
	while (test--) {
		int n, m, k, l ; Int(n, m, k, l) ;
		for (int i = 1 ; i <= n ; ++i) {
			for (int j = 1 ; j <= m ; ++j)
				Int(cell[i][j]) ;
			call(i, m, k, mx[i]) ;
		}
		DS.assign(2, SegmentTree(m)) ;
		maxify(m, l + 1, Q[0], mx[1], mx[1]) ; 
		// for(int i = 1 ; i <= m ; ++i){
		// 	cout << Q[0][i] << " \n"[i == m] ; 
		// }
		int itr = 0 ;
		for (int i = 2 ; i <= n ; ++i, itr ^= 1) {
			ll q[m + 1] ;
			for (int j = 1 ; j <= m ; ++j) {
				ll V = Q[itr][j] ;
				//error(V, mx[i][j])
				ll cur = V + mx[i][j] ;
				q[j] = cur ;
				//error(cur)
			}
			maxify(m, l + 1, Q[!itr], q, q) ; 
			// for(int ii = 1 ; ii <= m ; ++ii){
			// 	cout << Q[!itr][ii] << " \n"[ii == m] ; 
			//}
		}
		ll res = 0 ; 
		for(int i = 1 ; i <= m ; ++i)
			res = max(res, Q[itr][i]) ; 
		printf("%lld\n", res);
	}


#ifndef ONLINE_JUDGE
	fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
	return 0 ;
}