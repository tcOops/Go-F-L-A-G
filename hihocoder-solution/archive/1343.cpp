    #include <stdio.h>  
    #include <ctype.h>  
    #include <string.h>  
    #include <stdlib.h>  
    #include <limits.h>  
    #include <math.h>  
    #include <algorithm>  
    #include <vector>  
    #include <queue>  
    using namespace std;  
    typedef long long ll;  
      
    int n;  
    vector<int> G[100005];  
    int indeg[100005];  
      
    int logk[100005][11];  
    int kk[100005];  
      
    int parent[20][100005];  
    int depth[100005];  
    int lca(int u,int v){  
        if(depth[u]>depth[v])swap(u,v);  
        for(int k=0;k<19;++k){  
            if((depth[v]-depth[u])>>k&1){  
                v=parent[k][v];  
            }  
        }  
        if(u==v)return u;  
        for(int k=18;k>=0;--k){  
            if(parent[k][u]!=parent[k][v]){  
                u=parent[k][u];  
                v=parent[k][v];  
            }  
        }  
        return parent[0][u];  
    }  
    int main(){  
        scanf("%d",&n);  
        for(int i=1;i<=n;i++){  
            int k,id;  
            scanf("%d",&k);  
            kk[i]=k;  
            indeg[i]=k;  
            for(int j=0;j<k;j++){  
                scanf("%d",&id);  
                logk[i][j]=id;  
                G[id].push_back(i);  
            }  
        }  
          
        vector<int> seq;  
        queue<int> q;  
        q.push(0);  
        while(!q.empty()){  
            int x=q.front();q.pop();  
            seq.push_back(x);  
            for(int i=0;i<G[x].size();++i){  
                int y=G[x][i];  
                --indeg[y];  
                if(!indeg[y]){  
                    q.push(y);  
                }  
            }  
        }  
          
        int ans=0;  
          
        for(int i=0;i<20;i++)parent[0][i]=-1;  
        depth[0]=0;  
        for(int i=0;i<=n;++i){  
            if(seq[i]==0)continue;  
            int x=seq[i];  
            int par=logk[x][0];  
            for(int i=1;i<kk[x] && par>0;++i){  
                par=lca(par,logk[x][i]);  
            }  
            if(par==0) ++ans;  
              
            parent[0][x]=par;  
            depth[x]=depth[par]+1;  
            for(int k=1;k<18;++k){  
                if(parent[k-1][x]<0) parent[k][x]=-1;  
                else parent[k][x]=parent[k-1][parent[k-1][x]];  
            }  
        }  
        printf("%d\n",ans);  
        return 0;  
    }  