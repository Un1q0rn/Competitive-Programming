#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
const int INF = 1e9;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = INF;
    for(int i=1;i<=n;i++){
        vector<int> dist(n+1,INF);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while(sz(q)){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                if(dist[v] == INF){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
                else if(dist[v] >= dist[u]){
                    ans = min(ans,dist[v]+dist[u]+1);
                }
            }
        }
    }
    cout << (ans != INF ? ans:-1);
    return 0;
}
