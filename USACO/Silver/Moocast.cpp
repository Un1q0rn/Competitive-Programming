#include <bits/stdc++.h>
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

struct A{
    int x,y,w;
};
vector<A> a;
vector<vector<int>> adj;
vector<bool> visited;
int dfs(int u){
    visited[u] = true;
    int cnt=0;
    for(auto v:adj[u]){
        if(!visited[v]){
            visited[v] = true;
            cnt += dfs(v)+1;
        }
    }
    return cnt;
}
int main() {
    setIO("moocast");
    int n;cin >> n;
    adj.resize(n);
    for(int i=0;i<n;i++){
        int x,y,w;cin >> x >> y >> w;
        a.pb({x,y,w});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int dist = (a[i].x - a[j].x)*(a[i].x - a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y);
            if(dist <= a[i].w*a[i].w){
                adj[i].pb(j);
            }
        }
    }
    int ans=1;
    for(int i=0;i<n;i++){
        visited.assign(n,false);
        visited[i] = true;
        int cnt = dfs(i)+1;
        ans = max(ans,cnt);
    }
    cout << ans << '\n';
    return 0;
}
