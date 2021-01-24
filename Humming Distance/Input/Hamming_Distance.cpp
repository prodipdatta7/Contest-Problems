/**
 *    +--+--+--++--++--In the name of ALLAH--++--++--+--+--+
 *
 *    author:  skmonir
 *    created: 29-Nov-2019 21:17:54
**/

#include <bits/stdc++.h>

using namespace std;

#define endl                '\n'
#define TN                  typename
#define mod                 1000000007LL
#define len(x)              (int) x.size()
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define mem(x, y)           memset(x, y, sizeof x)
#define FOR(x, l, r)        for (int x = l; x <= r; ++x)
#define ROF(x, l, r)        for (int x = l; x >= r; --x)

template <TN T> inline void Int(T &n) {
    n = 0; int f = 1; register int ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
    for (; isdigit(ch); ch = getchar()) n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}

template <TN T> T gcd(T a, T b) {return !b ? a : gcd(b, a % b);}
template <TN T> inline void umin(T &a, T b) {a = a < b ? a : b;}
template <TN T> inline void umax(T &a, T b) {a = a > b ? a : b;}
template <TN T, TN W> inline void Int(T &x, W &y) {Int(x), Int(y);}
template <TN T, TN W, TN Q> void Int(T &x, W &y, Q &z) {Int(x, y), Int(z);}

const int N = 1e6 + 7;
const int inf = 1e9 + 7;

int n, m;
char s[N], t[N];

int solve() {
    scanf("%d %d", &n, &m);
    scanf("%s %s", s + 1, t + 1);

    if (m > n) {
        puts("0");
        return 0;
    }

    vector<int> cnt(26, 0);

    for (int i = 1; i <= n - m; ++i) {
        ++cnt[s[i] - 'a'];
    }

    long long total = 1LL * m * (n - m + 1), reject = 0LL;

    int i = n - m + 1, j = 0, k = 1;
    while (i <= n) {
        ++cnt[s[i] - 'a'];
        if (j > 0) {
            --cnt[s[j] - 'a'];
        }
        reject += cnt[t[k] - 'a'];
        ++i, ++j, ++k;
    }

    printf("%lld\n", total - reject);

    return 0;
}

/*
5 3
abdas ace
*/

// abcdabcdabcd
// abc

int main() {
    freopen("input_88.txt","r",stdin) ;
    int tests = 1, CaseNo = 0; //Int(tests);
    while (tests--) {
        //printf("Case %d: ", ++CaseNo);
        solve();
    }
    return 0;
}