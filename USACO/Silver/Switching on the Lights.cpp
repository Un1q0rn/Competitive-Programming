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
const int N = 1e2+10;
int vis[N][N],light[N][N];
vector<pair<int,int>> grid[N][N];
queue<pair<int,int>> q;
int n,m;
int main() {
    setIO("lightson");
    cin >> n >> m;
    while(m--){
        int x,y,a,b;cin >> x >> y >> a >> b;
        grid[x][y].push_back({a,b});
    }
    q.push({1,1});
    vis[1][1] = 1;
    light[1][1] = 1;
    while(sz(q)){
        int ni = q.front().first,nj = q.front().second;
        q.pop();
        for(auto [x,y]:grid[ni][nj]){
            light[x][y] = 1;
            if(vis[x][y]) continue;
            for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
                if(abs(i) == abs(j)) continue;
                int ii = x+i,jj = y+j;
                if(ii < 1 || ii > n || jj < 1 || jj > n) continue;
                if(vis[ii][jj]){
                    vis[x][y] = 1;
                    q.push({x,y});
                    continue;
                }
            }
        }
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = ni+i,jj = nj+j;
            if(ii < 1 || ii > n || jj < 1 || jj > n) continue;
            if(vis[ii][jj] || !light[ii][jj]) continue;
            vis[ii][jj] = 1;
            q.push({ii,jj});
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ans += light[i][j];
        }
    }
    cout << ans;
    return 0;
}
