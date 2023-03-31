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
const int di[4]{1,-1,0,0},dj[4]{0,0,1,-1};
int main() {
    setIO("ccski");
    int n,m;cin >> n >> m;
    vector<vector<int>> a(n+1,vector<int>(m+1)),mark(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    int si,sj;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;cin >> x;
            if(x){
                si = i;
                sj = j;
                mark[i][j] = 1;
            }
        }
    }
    int l = 0,r = 1e9; 
    while(l<r){
        int mid = l+((r-l)>>1);
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n+1,vector<int>(m+1));
        vis[si][sj] = 1;
        q.push({si,sj});
        while(sz(q)){
            int ni = q.front().f,nj = q.front().s;
            q.pop();
            for(int k=0;k<4;k++){
                int ii=ni+di[k],jj=nj+dj[k];
                if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
                if(vis[ii][jj] || abs(a[ni][nj]-a[ii][jj]) > mid) continue;
                vis[ii][jj] = 1;
                q.push({ii,jj});
            }
        }
        int ok = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(mark[i][j] && !vis[i][j]){
                    ok = 0;
                    break;
                }
            }
        }
        if(ok){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    cout << r;
    return 0;
}
