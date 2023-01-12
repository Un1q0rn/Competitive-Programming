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
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
const int N = 1e5+10;
int n,m;
vector<int> adj[N],a;
int vis[N];
void dfs(int u){
    for(auto v:adj[u]){
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
    a.pb(u);
}
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    cin >> n >> m;
    while(m--){
        int u,v;cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i=1;i<=n;i++) {
        if(vis[i]) continue;
        vis[i] = 1;
        dfs(i);
    }
    reverse(all(a));
    vector<int> ord(n+1);
    for(int i=1;i<=n;i++) {
        ord[a[i-1]] = i;
    }
    for(int i=1;i<=n;i++){
        for(auto j:adj[i]){
            if(ord[i] >= ord[j]){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(auto e:a) cout << e << ' ';
    return 0;
}
