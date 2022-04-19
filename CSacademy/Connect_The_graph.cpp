#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back

const int N = 1e5;
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
    if(root_nodes.size()-1 > free_edge.size()) cout << -1;
    else{
        cout << root_nodes.size()-1 << '\n';
        while(root_nodes.size()>1){
            int a = root_nodes.front();
            int b = root_nodes.back();
            root_nodes.pop_back();
            auto deleted_edge = free_edge.back();
            free_edge.pop_back();
            cout << deleted_edge.first << ' ' << deleted_edge.second << ' ' << a << ' ' << b << '\n';
        }
    }
    return 0;
}
