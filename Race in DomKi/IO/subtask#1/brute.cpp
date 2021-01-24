/**
     *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
     *
     *  author  :   Prodip Datta
     *  handle  :   prodipdatta7
     *  created :   Tuesday 11-August, 2020  09:37:43 PM
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
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}

/*...... ! Code starts from here ! ......*/

vector < vector < int > > g ;
int par[N][20], dep[N], a[N] ;

void dfs(int s, int p = 0) {
	par[s][0] = p ;
	dep[s] = 1 + dep[p] ;
	for (int i = 1 ; i < 20 ; ++i)
		par[s][i] = par[par[s][i - 1]][i - 1] ;
	for (int i : g[s]) {
		if (i == p)continue ;
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

bool type1(int x, int y) {
	if (x == y)return 1 ;
	int A = LCA(x, y) ;
	vector < int > cnt(61, 0) ;
	if (x == A or y == A) {
		if (x == A)swap(x, y) ;
		while (true) {
			cnt[a[x]] ^= 1 ;
			if (x == A)break ;
			x = par[x][0] ;
		}
	}
	else {
		while (true) {
			cnt[a[x]] ^= 1 ;
			if (x == A)break ;
			x = par[x][0] ;
		}
		while (true) {
			if (y == A)break ;
			cnt[a[y]] ^= 1 ;
			y = par[y][0] ;
		}
	}
	for (int i = 1 ; i <= 60 ; ++i)
		cnt[i] += cnt[i - 1] ;
	return cnt[60] <= 1 ;
}

void call(int x, int y, int A, vector < int > &val) {
	if (x == A or y == A) {
		if (x == A) {
			while (true) {
				val.push_back(a[y]) ;
				if (y == A)break ;
				y = par[y][0] ;
				//error(x, 1)
			}
			reverse(all(val)) ;
		} else {
			while (true) {
				val.push_back(a[x]) ;
				if (x == A)break ;
				x = par[x][0] ;
				//error(x, 1)
			}
		}

	}
	else {
		vector < int > tmp ;
		while (true) {
			val.push_back(a[x]) ;
			if (x == A)break ;
			x = par[x][0] ;
			//error(x, 2.1)
		}
		while (true) {
			if (y == A)break ;
			tmp.push_back(a[y]) ;
			y = par[y][0] ;
			//error(y, 2.2)
		}
		reverse(all(tmp)) ;
		for (int t : tmp)
			val.push_back(t) ;
	}
}

bool type2(int x, int y) {
	int A = LCA(x, y) ;
	vector < int > val ;
	call(x, y, A, val) ;
	int i = 0, j = sz(val) - 1 ;
	// for (int i : val)
	// 	cout << i << ' ' ;
	// cout << '\n' ;
	while (i < j) {
		if (val[i] != val[j])return 0 ;
		++i, --j ;
	}
	return 1 ;
}

bool type3(int x, int y, int p, int q) {
	int A = LCA(x, y) ;
	int B = LCA(p, q) ;
	vector < int > L, R ;
	call(x, y, A, L) ;
	call(p, q, B, R) ;
	return L == R ;
}

void clr(int n) {
	for (int i = 0 ; i <= n ; ++i) {
		for (int j = 0 ; j < 20 ; ++j)
			par[i][j] = 0 ;
		a[i] = 0 ;
		dep[i] = 0 ;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	clock_t tStart = clock();
	freopen("1.in", "r", stdin) ;
	freopen("1.out", "w", stdout) ;
#endif

	int test = 1 , tc = 0 ;
	Int(test) ;
	while (test--) {
		int n ; Int(n) ;
		for (int i = 1 ; i <= n ; ++i)
			Int(a[i]) ;
		g.assign(n + 1, vi()) ;
		for (int i = 1 ; i < n ; ++i) {
			int x, y ; Int(x, y) ;
			g[x].push_back(y) ;
			g[y].push_back(x) ;
		}
		dfs(1) ;
		int q ; Int(q) ;
		printf("Case %d:\n", ++tc);
		while (q--) {
			int tp, x, y ; Int(tp, x, y) ;
			if (tp == 1) {
				puts(type1(x, y) ? "YES" : "NO");
			}
			else if (tp == 2) {
				puts(type2(x, y) ? "YES" : "NO");
			}
			else {
				int z, w ;
				Int(z, w) ;
				puts(type3(x, y, z, w) ? "YES" : "NO");
			}
		}
		clr(n) ;
	}

#ifndef ONLINE_JUDGE
	fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
	return 0 ;
}