#include <bits/stdc++.h>
using namespace std;
#define N 10000 + 5
#define M 32768 + 5
#define INF 1234567890
#define ls(x) x << 1
#define rs(x) x << 1 | 1


int Case, Test, n, m, l;

struct Segment_Tree
{
	int Min, del;
}h[M];

inline void Build(int x, int l, int r)
{
	h[x].Min = r == 0 ? 0 : INF;
	h[x].del = INF;
	if (l == r) return ;
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
}

inline void update(int x)
{
	h[x].Min = min(h[ls(x)].Min, h[rs(x)].Min);
}

inline void apply(int x, int w)
{
	h[x].Min = min(h[x].Min, w);
	h[x].del = min(h[x].del, w);
}

inline void push(int x)
{
	if (h[x].del < INF)
	{
		apply(ls(x), h[x].del);
		apply(rs(x), h[x].del);
		h[x].del = INF;
	}
}

inline void Modify(int x, int l, int r, int s, int t, int w)
{
	if (l == s && r == t)
	{
		apply(x, w);
		return ;
	}
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, s, t, w);
	else if (s > mid) Modify(rs(x), mid + 1, r, s, t, w);
	else Modify(ls(x), l, mid, s, mid, w), Modify(rs(x), mid + 1, r, mid + 1, t, w);
	update(x);
}

inline int Query(int x, int l, int r, int t)
{
	if (l == r) return h[x].Min;
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) return Query(ls(x), l, mid, t);
	else return Query(rs(x), mid + 1, r, t);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (scanf("%d", &Case), Test = 1; Test <= Case; Test ++)
	{
		scanf("%d%d%d", &n, &m, &l);
		Build(1, 0, l);
		for (int i = 1; i <= n; i ++)
		{
			int a, b, val;
			scanf("%d%d%d", &a, &b, &val);
			for (int j = max(l - a, -1); ~j; j --)
			{
				int s = j + a, t = min(j + b, l), w = Query(1, 0, l, j);
				if (w == INF) continue ;
				Modify(1, 0, l, s, t, w + val);
			}
		}
		int res = Query(1, 0, l, l);
		printf("Case #%d: ", Test);
		if (res > m) puts("IMPOSSIBLE");
			else printf("%d\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
