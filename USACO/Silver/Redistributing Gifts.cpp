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

const int N = 550;
vector<int> adj[N],revadj[N],path;
int vis[N],vis2[N],comp[N];

void dfs(int u){
    vis[u] = 1;
    for(auto v:adj[u]){
        if(vis[v]) continue;
        dfs(v);
    }
    path.push_back(u);
}

void dfs2(int u,vector<int> &comp_path){
    vis2[u] = 1;
    for(auto v:revadj[u]){
        if(vis2[v]) continue;
        dfs2(v,comp_path);
    }

    comp[u] = 1;
    comp_path.push_back(u);
}

int main() {
    setIO("");
    int n;cin >> n;
    for(int i=0;i<n;i++){
        vector<int> a(n);
        for(auto &e:a) {
            cin >> e;
            e--;
        }
        for(int j=0;j<n;j++){
            adj[i].push_back(a[j]);
            if(i == a[j]) break;
        }

        for(auto j:adj[i]) revadj[j].push_back(i);
    }

    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        dfs(i);
    }

    reverse(all(path));

    vector<int> ans(n);
    for(auto i : path){
        if(vis2[i]) continue;
        vector<int> comp_path;
        dfs2(i,comp_path);

        for(auto j:comp_path){
            for(auto k:adj[j]){
                if(comp[k]){
                    ans[j] = k + 1;
                    break;
                }
            }
        }

        for(auto j:comp_path) comp[j] = 0;
    }

    for(auto e:ans) cout << e << '\n';

    return 0;
}
 
