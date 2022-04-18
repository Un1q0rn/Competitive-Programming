#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;
queue<int> q;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k,n,m;cin >> k >> n >> m;
    adj.resize(n+1);
    dist.resize(n+1);
    visited.resize(n+1);
    fill(dist.begin(),dist.end(),INT_MAX);
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
    }
    q.push(1);
    dist[1] = 0;
    visited[1] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto u:adj[v]){
            if(!visited[u]){
                visited[u] = true;
                dist[u] = min(dist[u],dist[v]+1);
                q.push(u);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dist[i]<=k){
            ans = i;
        }
    }
    cout << ans;
    return 0;
}
