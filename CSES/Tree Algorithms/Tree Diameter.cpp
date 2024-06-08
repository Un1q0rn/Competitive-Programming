#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin >> u >> v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto bfs = [&](int i){
        vector<int> dist(n,1e9);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        while(sz(q)){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                if(dist[u]+1 < dist[v]){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    };
    vector<int> dist1 = bfs(0);
    vector<int> dist2 = bfs(max_element(all(dist1))-dist1.begin());
    cout << *max_element(all(dist2));
    return 0;
}
