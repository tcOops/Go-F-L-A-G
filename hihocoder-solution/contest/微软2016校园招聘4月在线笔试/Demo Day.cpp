#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
	int x, y;
	int d; //0 - now goes right, 1 - now goes down
}nd, nd2;

queue <node> que;
char mp[110][110];
int dp[110][110][2];
int n, m;

void init() {
    memset(mp,0,sizeof(mp));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dp[i][j][0] = dp[i][j][1] = -1;
	dp[0][0][1] = 0;
	if(mp[0][0]=='b')
	    dp[0][0][1] = 1;
	while (!que.empty())
		que.pop();
}

int main() {
	int i, j;
	int cnt;
	scanf("%d%d", &n, &m);
		init();
		for (i = 0; i < n; i++)
			scanf("%s", mp[i]);
		nd.x = nd.y = 0;
		nd.d = 0;
		que.push(nd);
		while (!que.empty()) {
			nd = que.front();
			que.pop();
			if (nd.x == n-1 && nd.y == m-1)
				continue;
			if (nd.d == 0) {
				i = nd2.x = nd.x;
				nd2.d = 1;
				cnt = 0;
				for (j = nd.y+1; j < m; j++) {
					if (mp[i][j] == 'b') {
						nd2.y = j-1;
						if (dp[nd2.x][nd2.y][nd.d] == -1 || dp[nd2.x][nd2.y][nd.d] > dp[nd.x][nd.y][nd2.d]+cnt) {
							dp[nd2.x][nd2.y][nd.d] = dp[nd.x][nd.y][nd2.d]+cnt;
							que.push(nd2);
						}
						cnt++;
					}
					if (mp[i][j] == '.') {
						nd2.y = j-1;
						if (dp[nd2.x][nd2.y][nd.d] == -1 || dp[nd2.x][nd2.y][nd.d] > dp[nd.x][nd.y][nd2.d]+cnt+1) {
							dp[nd2.x][nd2.y][nd.d] = dp[nd.x][nd.y][nd2.d]+cnt+1;
							que.push(nd2);
						}
						
					}
				}
				nd2.y = m-1;
				if (dp[nd2.x][nd2.y][nd.d] == -1 || dp[nd2.x][nd2.y][nd.d] > dp[nd.x][nd.y][nd2.d]+cnt) {
					dp[nd2.x][nd2.y][nd.d] = dp[nd.x][nd.y][nd2.d]+cnt;
					que.push(nd2);
				}
			} else {
				j = nd2.y = nd.y;
				nd2.d = 0;
				cnt = 0;
				for (i = nd.x+1; i < n; i++) {
					if (mp[i][j] == 'b') {
						nd2.x = i-1;
						if (dp[nd2.x][nd2.y][nd.d] == -1 || dp[nd2.x][nd2.y][nd.d] > dp[nd.x][nd.y][nd2.d]+cnt) {
							dp[nd2.x][nd2.y][nd.d] = dp[nd.x][nd.y][nd2.d]+cnt;
							que.push(nd2);
						}
						cnt++;
					}
					if (mp[i][j] == '.') {
						nd2.x = i-1;
						if (dp[nd2.x][nd2.y][nd.d] == -1 || dp[nd2.x][nd2.y][nd.d] > dp[nd.x][nd.y][nd2.d]+cnt+1) {
							dp[nd2.x][nd2.y][nd.d] = dp[nd.x][nd.y][nd2.d]+cnt+1;
							que.push(nd2);
						}
						
					}
				}
				nd2.x = n-1;
				if (dp[nd2.x][nd2.y][nd.d] == -1 || dp[nd2.x][nd2.y][nd.d] > dp[nd.x][nd.y][nd2.d]+cnt) {
					dp[nd2.x][nd2.y][nd.d] = dp[nd.x][nd.y][nd2.d]+cnt;
					que.push(nd2);
				}
			}
		}
		if (dp[n-1][m-1][0] == -1 && dp[n-1][m-1][1] == -1) {
			while(1);
		} else if (dp[n-1][m-1][0] == -1) {
			printf("%d\n", dp[n-1][m-1][1]);
		} else if (dp[n-1][m-1][1] == -1) {
			printf("%d\n", dp[n-1][m-1][0]);
		} else {
			printf("%d\n", min(dp[n-1][m-1][0], dp[n-1][m-1][1]));
		}
	return 0;
}