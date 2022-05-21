#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const ll INF = 1e18;
const int N = 1e5+100;
struct A{
    int v,use;
    ll w;
    bool operator < (const A&o) const {
        return w>o.w;
    }
};
vector<pi> adj[N];
ll dis[N][2];
priority_queue<A> pq;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        dis[i][0] =dis[i][1] = INF;
    }
    while(m--){
        int u,v,w;cin >> u >> v >> w;
        adj[u].pb({v,w});
    }
    dis[1][0] = 0;
    pq.push({1,0,0});
    while(!pq.empty()){
        int v = pq.top().v,nuse = pq.top().use;
        ll w = pq.top().w;
        pq.pop();
        if(w != dis[v][nuse]) continue;
        if(v == n) break;
        for(auto x:adj[v]){
            if(!nuse){
                if(w+x.second/2 < dis[x.first][1]){
                    dis[x.first][1] = w+x.second/2;
                    pq.push({x.first,1,dis[x.first][1]});
                }
            }
            if(w+x.second < dis[x.first][nuse]){
                dis[x.first][nuse] = w+x.second;
                pq.push({x.first,nuse,dis[x.first][nuse]});
            }
        }
    }
    cout << dis[n][1];
    return 0;
}
