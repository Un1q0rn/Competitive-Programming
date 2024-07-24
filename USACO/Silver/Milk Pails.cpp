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
    setIO("pails");
    int x,y,k,m;cin >> x >> y >> k >> m;
    vector<vector<int>> dis(x + 10,vector<int>(y + 10,-1));
    queue<pair<int,int>> q;
    dis[0][0] = 0;
    q.push({0,0});
    int ans = 1e9;
    while(sz(q)){
        int nx = q.front().first,ny = q.front().second;
        q.pop();
        int d = dis[nx][ny];
        ans = min(ans,abs(m - (nx + ny)));
        if(d == k) continue;
        if(dis[0][ny] == -1){
            dis[0][ny] = d + 1;
            q.push({0,ny});
        }
        if(dis[nx][0] == -1){
            dis[nx][0] = d + 1;
            q.push({nx,0});
        }
        if(dis[x][ny] == -1){
            dis[x][ny] = d + 1;
            q.push({x,ny});
        }
        if(dis[nx][y] == -1){
            dis[nx][y] = d + 1;
            q.push({nx,y});
        }
        if(dis[max(0,nx - (y - ny))][min(y,ny + nx)] == -1){
            dis[max(0,nx - (y - ny))][min(y,ny + nx)] = d + 1;
            q.push({max(0,nx - (y - ny)),min(y,ny + nx)});
        }
        if(dis[min(x,nx + ny)][max(0,ny - (x - nx))] == -1){
            dis[min(x,nx + ny)][max(0,ny - (x - nx))] = d + 1;
            q.push({min(x,nx + ny),max(0,ny - (x - nx))});
        }
    }
    cout << ans;
    return 0;
}
