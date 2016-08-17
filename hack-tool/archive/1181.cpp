#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> VI;
const int mxn = 1001;
int n, m;
int deg[mxn], p[mxn][mxn];
VI ans;
void dfs(int u){
	for(int i = 1; i <= n; ++i){
		if(p[u][i] == 0) continue;
		--p[u][i];
		--p[i][u];
		dfs(i);
	}
	ans.push_back(u);
}
int main(){
	scanf("%d %d", &n, &m);
	while(m--){
		int u, v;
		scanf("%d %d", &u, &v);
		++p[u][v];
		++p[v][u];
	}
	dfs(1);
	for(int i = 0; i < ans.size(); ++i)
		printf("%d ", ans[i]);
	return 0;
}