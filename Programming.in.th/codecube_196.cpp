#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const ll INF = 1e18;
const int N = 1e5+100;
const ll MOD = 1e9+7;
struct A{
    int v;
    ll w;
    bool operator < (const A&o) const{
        return w>o.w;
    } 
};
vector<A> adj[N];
priority_queue<A> pq;
ll dist[N],dista[N],distb[N],mark[N];
int n,m,a,b,c,d;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        ll w;cin >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    cin >> a >> b >> c >> d;
    for(int i=1;i<=n;i++){
        dist[i] = dista[i] = distb[i] = INF;
    }
    dista[a] = 0;
    pq.push({a,0});
    while(!pq.empty()){
        int u = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if(w != dista[u]) continue;
        for(auto x:adj[u]){
            if(w+x.w < dista[x.v]){
                dista[x.v] = w+x.w;
                pq.push({x.v,dista[x.v]});
            }
        }
    }
    distb[b] = 0;
    pq.push({b,0});
    while(!pq.empty()){
        int u = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if(w != distb[u]) continue;
        for(auto x:adj[u]){
            if(w+x.w < distb[x.v]){
                distb[x.v] = w+x.w;
                pq.push({x.v,distb[x.v]});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dista[i]+distb[i] == dista[b]) mark[i] = 1;
    }
    dist[c] = 0;
    pq.push({c,0});
    while(!pq.empty()){
        int u = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if(w != dist[u]) continue;
        for(auto x:adj[u]){
            if(w+x.w < dist[x.v] && !mark[x.v]){
                dist[x.v] = w+x.w;
                pq.push({x.v,dist[x.v]});
            }
        }
    }
    if(dist[d] != INF)cout << dist[d] << '\n';
    else cout << -1  << '\n';
    return 0;
}
