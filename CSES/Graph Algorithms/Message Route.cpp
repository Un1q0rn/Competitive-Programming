#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int N = 1e5+10;
const int INF = 1e9;
int dist[N],pa[N];
vector<int> adj[N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    while(m--){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    while(sz(q)){
        int u= q.front();
        q.pop();
        for(auto x:adj[u]){
            if(dist[x] == INF){
                dist[x] = dist[u]+1;
                pa[x] = u;
                q.push(x);
            }
        }
    }
    if(dist[n] == INF) cout << "IMPOSSIBLE";
    else{
        cout << dist[n]+1 << '\n';
        vector<int> v;
        v.pb(n);
        while(v.back() != 1){
            v.pb(pa[v.back()]);
        }
        reverse(all(v));
        for(auto x:v) cout << x << ' ';
    }
    return 0;
}
