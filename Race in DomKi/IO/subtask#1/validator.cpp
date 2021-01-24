/**
     *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
     *
     *  author  :   Prodip Datta
     *  handle  :   prodipdatta7
     *  created :
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


struct dsu {
	int n ; vi par, rank ;
	dsu(int n = 0): n(n) {
		par.assign(n + 1, 0) ;
		rank.assign(n + 1, 1) ;
		for (int i = 1 ; i <= n ; ++i)par[i] = i ;
	}
	inline int Find(int s) {
		return par[s] = (par[s] == s ? s : Find(par[s])) ;
	}
	inline int merge(int a, int b) {
		int x = Find(a), y = Find(b) ;
		//error(x, y)
		if (x != y) {
			if (rank[x] < rank[y])swap(x, y) ;
			par[y] = x ;
			rank[x] += rank[y] ;
			return 1 ;
		}
		else return 0 ;
	}
};


vector < vector < int > > g ;
bool vis[N] ;

int dfs(int s , int p = -1) {
	//error(s, p, '\n')
	vis[s] = true ;
	int cnt = 1 ;
	for (int i = 0 ; i < (int)g[s].size() ; i++) {
		int u = g[s][i] ;
		if (u == p)continue;
		else if (vis[u]) {
			printf("Error!!! Graph Contains cycle.\n");
		}
		else {
			cnt += dfs(u, s);
		}
	}

	return cnt ;
}


int bfs(int s, int n) {
	vector < int > vis(n + 1, 0) ;
	queue < int > q ;
	vis[s] = 1 ;
	q.push(s) ;
	int tot = 0  ;
	while (!q.empty()) {
		int u = q.front() ;
		q.pop() ;
		int cnt = 0 ;
		++tot ;
		for (int i : g[u]) {
			if (!vis[i]) {
				q.push(i) ;
				vis[i] = 1 ;
			}
			else ++cnt ;
		}
		if (cnt > 1) {
			printf("Error!!! Graph Contains cycle.\n");
		}
	}
	return tot ;
}


int main() {
#ifndef ONLINE_JUDGE
	clock_t tStart = clock();
	freopen("1.in", "r", stdin) ;
	freopen("isvalid.out", "w", stdout) ;
#endif

	int test = 1 , tc = 0 ;
	int sumN = 0, sumQ = 0 ;
	Int(test) ;
	while (test--) {
		printf("Case %d:\n", ++tc);
		int n ; Int(n) ;
		sumN += n ;
		g.assign(n + 1, vi()) ;
		printf("The number of nodes is %d\n", n);
		if (n < 1)printf("Error!!! Number of nodes is less than Limit.\n");
		else if (n > 200000)printf("Error!!! Number of nodes is greater than Limit.\n");
		for (int i = 1 ; i <= n ; ++i) {
			int x ; Int(x) ;
			vis[i] = false ;
			if (x < 1)printf("Error!!! Rank should not less than 1.\n");
			else if (x > 60)printf("Error!!! Rank should not exceed 60.\n");
		}
		dsu var(n) ;
		g.assign(n + 1, vi()) ;
		for (int i = 0 ; i < n - 1 ; ++i) {
			int x, y ; Int(x, y) ;
			if (x < 1)printf("Error!!! Node %d is less than 1.\n", x);
			else if (x > n)printf("Error!!! Rank %d is greater than %d.\n", x, n);
			if (y < 1)printf("Error!!! Rank %d is less than 1.\n", y);
			else if (y > n)printf("Error!!! Rank %d is greater than %d.\n", y, n);
			if (!var.merge(x, y))printf("Error!!! Graph Contains cycle.\n");
			g[x].emplace_back(y) ;
			g[y].emplace_back(x) ;

		}
		int total = bfs(1, n) ;
		//int total = dfs(1) ;
		int p = var.Find(1) ;
		//cout << var.rank[p] << '\n' ;
		//cout << total << '\n' ;
		if (var.rank[p] != n)printf("Error!!! Graph is not connected!!!\n");
		if (total != n)printf("Error!!! Graph is not connected!!!\n");
		int q ; Int(q) ;
		sumQ += q ;
		//error(q)
		if (q < 1)printf("Error!!! q can't be less than 1.\n");
		else if (q > 200000)printf("Error!!! q can't be greater than 2e5.\n");
		int v = 0 ;
		while (q--) {
			int tp, a, b ; Int(tp, a, b) ;
			++v ;
			if (tp == 1) {
				if (a < 1 or b < 1 or a > n or b > n)printf("Error!!! Invalid query of type 1 at %d and test %d\n", v, tc);
			}
			else if (tp == 2) {
				if (a < 1 or b < 1 or a > n or b > n)printf("Error!!! Invalid query of type 2 at %d test %d\n", v, tc);
			}
			else {
				if (a < 1 or b < 1 or a > n or b > n)printf("Error!!! Invalid query of type 3.1 at %d test %d\n", v, tc);
				int c, d ; Int(c, d) ;
				if (c < 1 or d < 1 or c > n or d > n)printf("Error!!! Invalid query of type 3.2 at %d test %d\n", v, tc);
			}
		}
		//error(v, q)
		//assert(v == 200000) ;
		printf("Done!!!\n");
		printf("N = %d Q = %d\n", sumN, sumQ);
	}
	printf("N = %d Q = %d\n", sumN, sumQ);

#ifndef ONLINE_JUDGE
	fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
	return 0 ;
}