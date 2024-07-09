#include <bits/stdc++.h>
using namespace std;
 
#define ld long double 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

int main()
{
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
        vector<int> dist(n);
        queue<int> q;
        dist[i] = 1;
        q.push(i);
        while(sz(q)){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                if(dist[v]) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        return dist;
    };
    vector<int> dist1 = bfs(0);
    vector<int> dist2 = bfs(max_element(all(dist1)) - dist1.begin());
    vector<int> dist3 = bfs(max_element(all(dist2)) - dist2.begin());
    for(int i=0;i<n;i++){
        cout << max(dist2[i],dist3[i])-1 << ' ';
    }
    return 0;
}
