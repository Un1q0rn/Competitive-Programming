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
const int INF = 1e9;
struct EDGE{
    int r,d,s;
    bool operator< (const EDGE&o) const{
        return r > o.r;
    }
};
int main() {
    setIO("");
    int n,m;cin >> n >> m;
    vector<vector<EDGE>> adj(n+1,vector<EDGE>());
    vector<int> dist(n+1,INF),mark(n+1);
    for(int i=0;i<m;i++){
        int c,r,d,s;cin >> c >> r >> d >> s;
        adj[c].pb({r,d,s});
    }
    vector<int> layover(n+1);
    for(int i=1;i<=n;i++) cin >> layover[i];
    layover[1] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<sz(adj[i]);j++){
            adj[i][j].r-=layover[i];
        }
        sort(all(adj[i]));
    }
    dist[1] = 0;
    queue<EDGE> q;
    for(auto x:adj[1]){
        q.push(x);
    }
    vector<int> cnt(n+1);
    while(sz(q)){
        int d = q.front().d,s = q.front().s;
        //cout << s << '\n';
        q.pop();
        dist[d] = min(dist[d],s);
        while(cnt[d] < sz(adj[d]) && (s <= adj[d][cnt[d]].r)){
            q.push({adj[d][cnt[d]]});
            cnt[d]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
    }
    return 0;
}

