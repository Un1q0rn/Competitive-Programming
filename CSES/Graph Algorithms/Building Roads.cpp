#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back

const int N = 1e5+10;
vector<int> adj[N];
vector<bool> visited(N,false);
vector<pi> free_edge;
int pa[N];
void dfs(int u){
    visited[u] = true;
    for(auto v:adj[u]){
        if(v == pa[u]) continue;
        if(!visited[v]){
            pa[v] = u;
            dfs(v);
        }
        else{
            if(v < u){
                free_edge.pb({u,v});
            }
        }
    }
    return;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);adj[v].pb(u);
    }
    vector<int> root_nodes;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            root_nodes.pb(i);
            dfs(i);
        }
    }
    int ans = root_nodes.size()-1;
    cout << ans << '\n';
    for(int i=1;i<=ans;i++){
        cout << root_nodes[i-1] << ' ' << root_nodes[i] << '\n';
    }
    return 0;
}
