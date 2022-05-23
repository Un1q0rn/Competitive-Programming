#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int M = 998244353;
const int N = 17;
const int INF = 1e9;
vector<int> adj[N];
ll dist[1<<N][N];
queue<pi> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    while(m--){
        int u,v;cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dist[i][j] = INF;
        }
    }
    for(int i=0;i<n;i++){
        dist[1<<i][i] = 1;
        q.push({i,1<<i});
    }
    while(sz(q)){
        int u = q.front().first,bit=q.front().second;
        q.pop();
        for(auto v:adj[u]){
            int nbit = bit^(1<<v);
            if(dist[nbit][v] < INF) continue;
            dist[nbit][v] = dist[bit][u]+1;
            q.push({v,nbit});
        }
    }
    ll ans = 0;
    for(int i=1;i<(1<<n);i++){
        ll mn = INF;
        for(int j=0;j<n;j++){
            mn = min(mn,dist[i][j]);
        }
        ans += mn;
    }
    cout << ans << '\n';
    return 0;
}
