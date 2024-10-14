#include <bits/stdc++.h>
using namespace std;
 
#define ld long double 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,s;cin >> n >> s;
    vector<vector<char>> a(n + 1,vector<char>(n + 1));
    queue<pair<int,int>> qu;
    vector<vector<int>> bdist(n + 1,vector<int>(n + 1,1e9));
    int si = -1,sj = -1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            if(a[i][j] == 'H'){
                bdist[i][j] = 0;
                qu.push({i,j});
            }
            if(a[i][j] == 'M'){
                si = i;
                sj = j;
            }
        }
    }
    while(sz(qu)){
        int ni = qu.front().first,nj = qu.front().second;
        qu.pop();
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = ni + i,jj = nj + j;
            if(ii < 1 || ii > n || jj < 1 || jj > n) continue;
            if(bdist[ii][jj] != 1e9 || a[ii][jj] == 'T' || a[ii][jj] == 'D') continue;
            bdist[ii][jj] = bdist[ni][nj] + 1;
            qu.push({ii,jj});
        }
    }
    int ans = -1;
    int l = 0,r = n * n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(bdist[si][sj] <= mid){
            r = mid - 1;
            continue;
        }
        vector<vector<int>> dist(n + 1,vector<int>(n + 1,-1));
        queue<pair<int,int>> q;
        q.push({si,sj});
        dist[si][sj] = 0;
        bool ok = false;
        while(sz(q)){
            int ni = q.front().first,nj = q.front().second;
            q.pop();
            if(a[ni][nj] == 'D'){
                ok = true;
                break;
            }
            for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
                if(abs(i) == abs(j)) continue;
                int ii = ni + i,jj = nj + j;
                if(ii < 1 || ii > n || jj < 1 || jj > n) continue;
                if(dist[ii][jj] != -1) continue;
                if(bdist[ii][jj] <= mid + (dist[ni][nj] + 1) / s) continue;
                if(a[ii][jj] == 'T') continue;
                dist[ii][jj] = dist[ni][nj] + 1;
                q.push({ii,jj});
            }
        }
        if(ok){
            l = mid + 1;
            ans = mid;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
