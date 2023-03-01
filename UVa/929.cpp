#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const int INF = 1e9;
const int di[4] = {1,-1,0,0},dj[4] = {0,0,1,-1};
struct A{
    int i,j,w;
    bool operator < (const A&o) const{
        return w > o.w;
    }
};
void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1)),dist(n+1,vector<int>(m+1,INF));
    priority_queue<A> pq;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    pq.push({1,1,0});
    dist[1][1] = 0;
    while(sz(pq)){
        int ni = pq.top().i,nj = pq.top().j,nw = pq.top().w;
        pq.pop();
        if(dist[ni][nj] != nw) continue;
        for(int k=0;k<4;k++){
            int ii = ni+di[k],jj = nj+dj[k];
            if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
            if(dist[ii][jj] > dist[ni][nj]+a[ii][jj]){
                pq.push({ii,jj,dist[ii][jj] = dist[ni][nj]+a[ii][jj]});
            }
        }
    }
    cout << dist[n][m] << '\n';
}
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
