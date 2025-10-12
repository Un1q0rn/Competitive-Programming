#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int inf = 1e9;
const int MAXN = 2e5 + 10;

vector<int> adj[MAXN];
ll a[MAXN];
int n,q,start[MAXN],en[MAXN];
int cnt;


template <class T>
struct BIT{
    int n;
    vector<T> f;
    BIT(int size) {
        n = size;
        f.resize(n + 1);
    }

    void upd(int i,T v){
        i++;
        while(i <= n){
            f[i]+=v;
            i += i & -i;
        }
    }

    T qry(int i){
        i++;
        T res = 0;
        while(i > 0){
            res += f[i];
            i -= i & -i;
        }
        return res;
    }
};

void dfs(int u,int p){
    start[u] = cnt++;
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs(v,u);
    }
    en[u] = cnt;
}

void solve() {
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=0;i<n-1;i++){
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    BIT<ll> bit(n);
    for(int i=1;i<=n;i++){
        bit.upd(start[i],a[i]);
    }

    while(q--){
        int t;cin >> t;
        if(t == 1){
            int s;
            ll x;cin >> s >> x;
            ll d = x - a[s];
            a[s] = x;
            bit.upd(start[s],d);
        }
        else{
            int s;cin >> s;
            ll ans = bit.qry(en[s] - 1) - bit.qry(start[s] - 1);
            cout << ans << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
