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
    setIO("revegetate");
    int n,m;cin >> n >> m;
    vector<vector<int>> g(n);
    while(m--){
        int u,v;cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> plant(n);
    for(int u=0;u<n;u++){
        vector<int> ch(4);
        for(auto v:g[u]){
            if(v == u) continue;
            ch[plant[v]] = 1;
        }
        int p = 1;
        while(ch[p]) p++;
        plant[u] = p;
    }
    for(auto e:plant) cout << e;
    return 0;
}
