#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
#define setdecimal(x) cout << fixed << setprecision(x)

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
int main() {
    setIO("factory");
    int n;cin >> n;
    vector<int> in(n),out(n);
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin >> u >> v;
        u--;v--;
        g[v].push_back(u);
        in[u]++;
        out[v]++;
    }
    for(int i=0;i<n;i++){
        if(in[i] == 0){
            vector<int> vis(n);
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(sz(q)){
                int u = q.front();
                q.pop();
                for(auto v:g[u]){
                    if(vis[v]) continue;
                    q.push(v);
                    vis[v] = 1;
                }
            }
            int ch = 1;
            for(int j=0;j<n;j++){
                if(!vis[j]){
                    ch = 0;
                    break;
                }
            }
            if(ch){
                cout << i+1;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}
