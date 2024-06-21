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
int road[N][N][4],vis[N][N],cow[N][N];
int di[4]{1,-1,0,0},dj[4]{0,0,1,-1};
int n,k,m;
queue<pair<int,int>> q;
int dir(int r1,int c1,int r2,int c2){
    int i = r2-r1,j = c2-c1;
    if(i == 1 && j == 0) return 0;
    if(i == -1 && j == 0) return 1;
    if(i == 0 && j == 1) return 2;
    if(i == 0 && j == -1) return 3;
    return 0;
}
int main() {
    setIO("countcross");
    cin >> n >> k >> m;
    while(m--){
        int r1,c1,r2,c2;cin >> r1 >> c1 >> r2 >> c2;
        road[r1][c1][dir(r1,c1,r2,c2)] = 1;
        road[r2][c2][dir(r2,c2,r1,c1)] = 1;
    }
    while(k--){
        int r,c;cin >> r >> c;
        cow[r][c] = 1;
    }
    int ans = 0;
    vector<int> comp;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!cow[i][j] || vis[i][j]) continue;
            int cnt = 1;
            q.push({i,j});
            vis[i][j] = 1;
            while(sz(q)){
                int ni = q.front().first,nj = q.front().second;
                q.pop();
                for(int l=0;l<4;l++){
                    if(road[ni][nj][l]) continue;
                    int ii = ni+di[l],jj = nj+dj[l];
                    if(ii < 1 || ii > n || jj < 1 || jj > n) continue;
                    if(vis[ii][jj]) continue;
                    vis[ii][jj] = 1;
                    cnt+=cow[ii][jj];
                    q.push({ii,jj});
                }
            }
            comp.push_back(cnt);
        }
    }
    for(int i=0;i<sz(comp);i++){
        for(int j=i+1;j<sz(comp);j++){
            ans += comp[i]*comp[j];
        }
    }
    cout << ans;
    return 0;
}
