#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()

const int N = 1e5+100;
vector<int> adj[N],rev[N];
vector<pi> ans;
int visited[N];
void dfs1(int node){
    if(visited[node]) return;
    visited[node] = 1;
    for(auto u:adj[node]){
        if(!visited[u]) dfs1(u);
    }
}
void dfs2(int node){
    if(visited[node]) return;
    visited[node] = 1;
    for(auto u:rev[node]){
        if(!visited[u]) dfs2(u);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        rev[v].pb(u);
    }
    dfs1(n);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout << "NO\n" << n << ' ' << i;
            return 0;
        }
    }
    memset(visited,0,sizeof visited);
    dfs2(n);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout << "NO\n" << i << ' ' << n;
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
