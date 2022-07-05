#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ui unsigned int 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()
const int N = 1e3+10;
char a[N][N];
int vis[N][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            vis[i][j] = (a[i][j] == '#');
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(vis[i][j]) continue;
            if(a[i][j] == '.'){
                queue<pi> q;
                q.push({i,j});
                vis[i][j] = 1;
                while(sz(q)){
                    int ni = q.front().f,nj = q.front().s;
                    q.pop();
                    for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++){
                        if(abs(k) == abs(l)) continue;
                        int ii = ni+k,jj = nj+l;
                        if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
                        if(vis[ii][jj]) continue;
                        vis[ii][jj] = 1;
                        q.push({ii,jj});
                    }
                }
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
