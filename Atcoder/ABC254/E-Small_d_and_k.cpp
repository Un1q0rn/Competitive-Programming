#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<int> adj[n+1];
    while(m--){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> dist(n+1,-1);
    int Q;cin >> Q;
    while(Q--){
        int x,k;cin >> x >> k;
        dist[x] = 0;
        queue<int> q;
        vector<int> vs;
        q.push(x);
        while(sz(q)){
            int u = q.front();
            q.pop();
            vs.pb(u);
            if(dist[u] == k) continue;
            for(auto v:adj[u]){
                if(dist[v]!=-1) continue;
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
        int ans = 0;
        for(auto x:vs){
            ans+=x;
            dist[x] = -1;
        }
        cout << ans << '\n';
    }
    return 0;
}


