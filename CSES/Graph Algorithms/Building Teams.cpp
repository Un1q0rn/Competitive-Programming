#include <bits/stdc++.h> 
using namespace std; 

#define ll long long int 
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const int N = 1e5+10;
int n,m,ok;
vector<int> adj[N],vis(N),color(N);
void dfs(int u,int c){
    if(ok) return ;
    vis[u] = 1;
    color[u] = c;
    for(auto v:adj[u]){
        if(vis[v]){
            if(color[v] == c){
                ok = 1;
                return ;
            }
            continue;
        }
        dfs(v,c^1);
    }
}
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> n >> m;
    while(m--){
        int u,v;cin >> u >> v;
        adj[u].pb(v);adj[v].pb(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
        if(ok) break;
    }
    if(ok) cout << "IMPOSSIBLE";
    else{
        for(int i=1;i<=n;i++){
            cout << color[i]+1 << ' ';
        }
    }
    return 0;
}


