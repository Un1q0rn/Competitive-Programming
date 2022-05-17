#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ui unsigned int 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()
const int N = 3e3+100;
vector<int> adj[N];
queue<int> q;
int dist[N][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        q.push(i);
        dist[i][i] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto x:adj[u]){
                if(!dist[i][x] && x!=i){
                    dist[i][x] = dist[i][u]+1;
                    q.push(x);
                }
            }
        }
    }
    int q;cin >> q;
    while(q--){
        int s,t,x,u,v,y;cin >> s >> t >> x >> u >> v >> y;
        if(dist[s][t] <= x || dist[u][v] <= y) cout << "YES\n";
        else{
            if(dist[s][u]+dist[t][v]+2 <= x+y || dist[s][v]+dist[t][u]+2 <= x+y) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
