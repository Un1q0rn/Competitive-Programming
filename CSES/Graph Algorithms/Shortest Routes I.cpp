#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const ll INF = 1e18;
const int N = 1e5+10;

vector<pi> adj[N];
ll dist[N];
int n,m;
struct A{
    int v;
    ll w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
priority_queue<A> pq;
void dijkstra(int src){
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    dist[src] = 0;
    pq.push({src,0});
    while(!pq.empty()){
        ll cdist = pq.top().w;
        int node = pq.top().v;
        pq.pop();
        if(cdist != dist[node]) continue;
        for(auto u:adj[node]){
            if(cdist+u.second < dist[u.first]){
                pq.push({u.first,dist[u.first] = cdist+u.second});
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){ 
        int u,v,w;cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    dijkstra(1);
    for(int i=1;i<=n;i++){
        if(dist[i] == INF) dist[i] = -1;
        cout << dist[i] << ' ';
    }
    return 0;
}
