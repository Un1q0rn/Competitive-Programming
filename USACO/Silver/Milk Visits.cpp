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

const int N = 1e5+10;
vector<int> adj[N];
int comp[N],cnt = 1;
int n,m;
string s;
void dfs(int u,int ncnt,char c){
    comp[u] = ncnt;
    for(auto v:adj[u]){
        if(comp[v] || s[v] != c) continue;
        dfs(v,ncnt,c);
    }
}
int main() {
    setIO("milkvisits");
    cin >> n >> m >> s;
    s = " " + s;
    for(int i=0;i<n-1;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(comp[i]) continue;
        dfs(i,cnt,s[i]);
        cnt++;
    }
    while(m--){
        int u,v;cin >> u >> v;
        char c;cin >> c;
        if(comp[u] != comp[v]) cout << 1;
        else{
            cout << (s[u] == c);
        }
    }
    return 0;
}
