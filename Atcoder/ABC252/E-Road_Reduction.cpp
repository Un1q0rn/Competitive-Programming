#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int N = 2e5+100;
const ll INF = 1e18;
struct B{
    int v;
    ll w;
    int idx;
};
struct A{
    int v;
    ll w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
vector<B> adj[N];
ll dis[N];
int ans[N];
priority_queue<A> pq;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; 
        ll w;
        cin >> u >> v >> w;
        adj[u].pb({v,w,i+1});
        adj[v].pb({u,w,i+1});
    }
    for(int i=1;i<=n;i++) dis[i] = INF;
    dis[1] = 0;
    pq.push({1,0});
    while(!pq.empty()){
        int u = pq.top().v;
        ll w = pq.top().w;
        pq.pop();
        if(dis[u]!=w) continue;
        for(auto [v,ww,idx]:adj[u]){
            if(w+ww<dis[v]){
                dis[v] = w+ww;
                pq.push({v,dis[v]});
                ans[--v] = idx;
            }
        }
    }
    for(int i=1;i<n;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
