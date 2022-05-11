#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

const int N = 105;
vector<pi> edges;
vector<int> g[N];
int visited[N],adj[N][N];
void dfs(int cur){
    visited[cur] = 1;
    for(auto u:g[cur]){
        if(!visited[u] && !adj[cur][u]){
            dfs(u);
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while(1){
        int p,c;cin >> p >> c;
        if(!p && !c) break;
        for(int i=0;i<c;i++){
            int u,v;cin >> u >> v;
            edges.pb({u,v});
            g[u].pb(v),g[v].pb(u);
        }
        for(auto x:edges){
            memset(visited,0,sizeof visited);
            int u = x.f,v = x.s;
            adj[u][v] = adj[v][u] = 1;
            dfs(0);
            for(int i=0;i<p;i++){
                if(!visited[i]){
                    cout << "YES" << '\n';
                    goto here;
                }
            }
            adj[u][v] = adj[v][u] = 0;
        }
        cout << "NO" << '\n';
        here:;
        edges.clear();
        for(int i=0;i<p;i++) g[i].clear();
    }
    return 0;
}
