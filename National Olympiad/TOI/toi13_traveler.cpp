#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
const ll INF = 1e18;
const int N = 1e5+10;
struct A{
    ll v,w;
    bool operator < (const A&o) const{
        return w>o.w;
    }
};
A now;
vector<A> adj[N];
priority_queue<A> pq;
ll dist[N],disR[N];
int n,m,u,v,w,st,en,d;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> st >> en >> d;
    while(m--){
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    for(int i=0;i<n;i++){
        dist[i] = INF;
    }
    dist[st] = 0;
    pq.push({st,0});
    while(!pq.empty()){
        now = pq.top();pq.pop();
        for(auto x:adj[now.v]){
            if(now.w+x.w<dist[x.v]){
                dist[x.v] = now.w+x.w;
                pq.push({x.v,dist[x.v]});
            }
        }
    }
    if(dist[en] <= d){
        cout << en << ' ' << dist[en] << ' ' << 0;
        return 0;
    }
    ll mn = LLONG_MAX,pos = en;
    for(int i=0;i<n;i++){
        disR[i] = 1e9;
    }
    disR[en] = 0;
    pq.push({en,0});
    while(!pq.empty()){
        now = pq.top();pq.pop();
        for(auto x:adj[now.v]){
            if(now.w+x.w<disR[x.v]){
                disR[x.v] = now.w+x.w;
                pq.push({x.v,disR[x.v]});
                if(disR[x.v] <= mn && dist[x.v] <= d){
                    if(disR[x.v] == mn){
                        pos = min(pos,x.v);
                    }
                    else pos = x.v;
                    mn = min(mn,disR[x.v]);
                }
            }
        }
    }
    cout << pos << ' ' << dist[pos] << ' ' << mn;
    return 0;
}
