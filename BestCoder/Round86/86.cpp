#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
#define fi first
#define se second
#define MP make_pair

int read()
{
    int v = 0, f = 1;
    char c = getchar();
    while (c < 48 || 57 < c) {if (c == '-') f = -1; c = getchar();}
    while (48 <= c && c <= 57) v = v * 10 + c - 48, c = getchar();
    return v * f;
}

const int N = 60;
int dp[N][N][N][4];
struct EG
{
    int a, b;
} eg[N * 100];
const int MOD = 998244353;
int n, m, K, q, en, head[N], a[N];
int Abs(int a)
{
    return a < 0 ? -a : a;
}
void SetEdge(int u, int v)
{
    eg[++en] = (EG) {v, head[u]};
    head[u] = en;
}
void Main()
{
    n = read(), m = read(), K = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    en = 0;
    for (int i = 1; i <= n; i++) head[i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        SetEdge(v, u);
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (Abs(a[i] - a[j]) <= K && Abs(a[j] - a[k]) <= K && Abs(a[k] - a[i]) <= K)
                    dp[i][j][k][0] = 1;
    for (int i = n; i >= 1; i--)
        for (int j = n; j >= 1; j--)
            for (int k = n; k >= 1; k--)
            {
                for (int e = head[i]; e; e = eg[e].b)
                {
                    int v = eg[e].a;
                    (dp[v][j][k][1] += dp[i][j][k][0]) %= MOD;
                }
                for (int e = head[j]; e; e = eg[e].b)
                {
                    int v = eg[e].a;
                    (dp[i][v][k][2] += dp[i][j][k][1]) %= MOD;
                }
                for (int e = head[k]; e; e = eg[e].b)
                {
                    int v = eg[e].a;
                    if (Abs(a[i] - a[j]) <= K && Abs(a[j] - a[v]) <= K && Abs(a[v] - a[i]) <= K)
                        (dp[i][j][v][0] += dp[i][j][k][2]) %= MOD;
                }
            }
    while (q--)
    {
        int a = read(), b = read(), c = read();
        printf("%d\n", dp[a][b][c][0]);
    }
}
int main()
{
    int T = read();
    while (T--) Main();
}
