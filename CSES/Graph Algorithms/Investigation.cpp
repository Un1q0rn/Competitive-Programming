#include <bits/stdc++.h>
using namespace std;
 
#define ld long double 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

const int MOD = 1e9+7;
const int N = 1e5;

struct A{
    int u;
    ll w;
    bool operator < (const A &o) const{
        return w > o.w;
    }
};

vector<pair<int,int>> adj[N];
ll dist[N],path[N];
int mn[N],mx[N];
int n,m;


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while(m--){
        int u,v,w;cin >> u >> v >> w;
        u--,v--;
        adj[u].push_back({v,w});
    }
    memset(dist,0x3f,sizeof(dist));
    priority_queue<A> pq;
    pq.push({0,0});
    dist[0] = 0;
    path[0] = 1;
    while(sz(pq)){
        int u = pq.top().u;
        ll d = pq.top().w;
        pq.pop();
        if(d != dist[u]) continue;
        for(auto e:adj[u]){
            int v = e.first;
            ll w = e.second;
            if(dist[v] == d + w){
                path[v] = (path[v] + path[u]) % MOD;
                mn[v] = min(mn[v],mn[u] + 1);
                mx[v] = max(mx[v],mx[u] + 1);
            }
            else if(dist[v] > d + w){
                dist[v] = d + w;
                path[v] = path[u];
                mx[v] = mx[u] + 1;
                mn[v] = mn[u] + 1;
                pq.push({v,dist[v]});
            }
        }
    }
    cout << dist[n-1] << ' ' << path[n-1] << ' ' << mn[n-1] << ' ' << mx[n-1];
    return 0;
}
