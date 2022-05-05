#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

char a[100][100];
int n,m,dp[100][100],mark[100][100],mx = 0,p=INT_MAX;
queue<pi> q;
void play(int ni,int nj){
    int cnt=0;
    for(int i=ni;i>=ni-mx+1;i--){
        for(int j=nj;j>=nj-mx+1;j--){
            if(a[i][j] != 'P' || mark[i][j]) continue;
            mark[i][j] = 1;
            cnt++;
            q.push({i,j});
            while(!q.empty()){
                int si = q.front().first;
                int sj = q.front().second;
                q.pop();
                for(int k=-1;k<=1;k++) for(int l=-1;l<=1;l++){
                    if(abs(k) == abs(l)) continue;
                    int ii = si+k;
                    int jj = sj+l;
                    if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
                    if(a[ii][jj] != 'P' || mark[ii][jj]) continue;
                    mark[ii][jj] = 1;
                    q.push({ii,jj});
                }
            }
            while(!q.empty()) q.pop();
        }
    }
    p = min(cnt,p);
    memset(mark,0,sizeof mark);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == 'T') continue;
            dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            mx = max(dp[i][j],mx);
        }
    }
    if(mx == 0){
        cout << "0 0";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(dp[i][j] == mx) {
                play(i,j);
            }
        }
    }
    cout << mx*mx << ' ' << p;
    return 0;
}
