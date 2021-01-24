/**
 *    +--+--+--++--++--In the name of ALLAH--++--++--+--+--+
 *
 *    author:  skmonir
 *    created: >
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
template <TN T, TN W, TN Q> inline void Int(T &x, W &y, Q &z) {Int(x, y), Int(z);}

const int N = 2e5 + 7;
const int inf = 1e9 + 7;
const int magic = 20;

int clr, color[N], color_size[N];
int sub[N], dep[N], par[N][magic + 5];

vector<int> g[N];

void dfs(int u, int p = -1) {
    color[u] = clr;
    ++color_size[clr];
    sub[u] = 1;
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    for (int i = 1; i <= magic; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (v != p) {
            dfs(v, u);
            sub[u] += sub[v];
        }
    }
}

int binaryLift(int u, int dist) {
    for (int i = magic; i >= 0; i--) {
        if (dist & (1 << i)) {
            u = par[u][i];
        }
    }
    return u;
}

int GetLCA(int a, int b) {
    if (dep[a] < dep[b]) {
        swap(a, b);
    }
    int dist = dep[a] - dep[b];
    a = binaryLift(a, dist);
    for (int i = magic; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            a = par[a][i], b = par[b][i];
        }
    }
    return a == b ? a : par[a][0];
}

int solve() {
    int n; Int(n);
    assert(1 <= n && n <= 200000);
    FOR (i, 2, n) {
        int u, v, w; Int(u, v, w);
        assert(1 <= u && u <= n);
        assert(1 <= v && v <= n);
        assert(0 <= w && w <= 1);
        if (w == 1) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            ++clr;
            dfs(i);
        }
    }

    int q; Int(q);
    assert(1 <= q && q <= 200000);
    while (q--) {
        int k; Int(k);
        assert(1 <= k && k <= 200000);
        vector<int> members(k);
        for (int &member : members) {
            Int(member);
            assert(1 <= member && member <= n);
        }
        if (k == 1) {
            printf("%d\n", color_size[color[members[0]]]);
            continue;
        }
        int m = members.size();
        bool isFromSameTree = true;
        for (int i = 1; i < m; ++i) {
            if (color[members[i - 1]] != color[members[i]]) {
                isFromSameTree = false;
            }
        }
        if (!isFromSameTree) {
            printf("0\n");
            continue;
        }

        int dist = 0, otherEnd = members[0];
        for (int i = 1; i < m; ++i) {
            int l = GetLCA(members[0], members[i]);
            int d = dep[members[0]] + dep[members[i]] - 2 * dep[l];
            if (d > dist) {
                dist = d;
                otherEnd = members[i];
            }
        }

        if (dist & 1) {
            printf("0\n");
            continue;
        }

        dist >>= 1;
        int center = otherEnd, lca = GetLCA(members[0], otherEnd);
        if (lca != members[0] && dep[members[0]] - dep[lca] >= dist) {
            center = binaryLift(members[0], dist);
        } else {
            center = binaryLift(otherEnd, dist);
        }

        int res = sub[center];
        set<int> rejectedAdjNodes;
        bool sameDistForAll = true;
        for (int i = 0; i < m; ++i) {
            int l = GetLCA(center, members[i]);
            int d = dep[center] + dep[members[i]] - 2 * dep[l];
            if (d != dist) {
                sameDistForAll = false;
                break;
            }
            if (l == center) {
                int child = binaryLift(members[i], dist - 1);
                if (rejectedAdjNodes.count(child) == 0) {
                    res -= sub[child];
                    rejectedAdjNodes.insert(child);
                }
            } else {
                rejectedAdjNodes.insert(par[center][0]);
            }
        }
        if (!sameDistForAll) {
            printf("0\n");
            continue;
        }
        if (rejectedAdjNodes.count(par[center][0]) == 0) {
            res += color_size[color[center]] - sub[center];
        }
        printf("%d\n", res);
    }

    return 0;
}

int main() {
    int tests = 1, CaseNo = 0; //Int(tests);
    while (tests--) {
        //printf("Case %d: ", ++CaseNo);
        solve();
    }
    return 0;
}