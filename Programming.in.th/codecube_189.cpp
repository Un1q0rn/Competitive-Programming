#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const ll INF = 1e18;
const int N = 1e5+10;
struct A{
    int v;
    ll w;
    int used;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};

vector<A> adj[N];
priority_queue<A> pq;
ll dist[N][2],allcost;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,s,t;cin >> n >> m >> s >> t; 
    while(m--){
        int u,v,w;cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        allcost+=w;
    }
    for(int i=0;i<n;i++){
        dist[i][0] = dist[i][1] = INF;
    }
    dist[s][0] = 0;
    pq.push({s,0,0});
    while(!pq.empty()){
        int node = pq.top().v;
        ll w = pq.top().w;
        int use = pq.top().used;
        pq.pop();
        if(w != dist[node][use]) continue;
        for(auto x:adj[node]){
            if(dist[node][use]+x.w < dist[x.v][use]){
                dist[x.v][use] = dist[node][use]+x.w;
                pq.push({x.v,dist[x.v][use],use});
            }
            if(!use && dist[node][use] < dist[x.v][1]){
                dist[x.v][1] = dist[x.v][0]-x.w;
                pq.push({x.v,dist[x.v][1],1});
            }
        }
    }
    cout << allcost-dist[t][1] << '\n';
    return 0;
}
