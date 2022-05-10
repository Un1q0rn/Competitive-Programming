#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 


const int N = 2010;
char a[N][N];
int dist[N][N];
queue<pi> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    memset(dist,127,sizeof dist);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == 'X') q.push({i,j}),dist[i][j] = 0;
        }
    }
    int ans = 0,cnt=0;
    while(!q.empty()){
        int ni = q.front().first,nj = q.front().second;
        q.pop();
        if(a[ni][nj] == 'A'){
            ans += dist[ni][nj];
            cnt++;
        }
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii =ni+i,jj = nj+j;
            if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
            if(a[ii][jj] == 'W') continue;
            if(dist[ii][jj] > dist[ni][nj]+1){
                dist[ii][jj] = dist[ni][nj]+1;
                q.push({ii,jj});
            }
        }
    }
    cout << cnt << ' ' << ans*2;
    return 0;
}
