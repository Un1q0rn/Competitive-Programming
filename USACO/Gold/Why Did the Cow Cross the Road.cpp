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

struct A{
    int x,y;
    ll w;
    bool operator < (const A &o) const{
        return w > o.w;
    }
};
int main() {
    setIO("visitfj");
    int n,t;cin >> n >> t;
    vector<vector<ll>> a(n+1,vector<ll>(n+1)),dist(n+1,vector<ll>(n+1,1e18));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    priority_queue<A> pq;
    dist[1][1] = 0;
    pq.push({1,1,0});
    while(sz(pq)){
        int x = pq.top().x;
        int y = pq.top().y;
        ll w = pq.top().w;
        pq.pop();
        for(int k=-3;k<=3;k++) for(int l=-3;l<=3;l++){
            if(abs(k) == abs(l)) continue;
            if(3 % (abs(k) + abs(l))) continue;
            int ii = x + k,jj = y + l;
            if(ii < 1 || ii > n || jj < 1 || jj > n) continue;
            if(dist[ii][jj] > w + a[ii][jj] + 3 * t){
                dist[ii][jj] = w + a[ii][jj] + 3 * t;
                pq.push({ii,jj,dist[ii][jj]});
            }
        }
        if(2 * n - x - y < 3){
            dist[n][n] = min(dist[n][n],dist[x][y] + t * (2 * n - x - y));
        }
    }
    cout << dist[n][n];
    return 0;
}
