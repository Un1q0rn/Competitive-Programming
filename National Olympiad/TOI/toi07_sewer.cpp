#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

char a[110][110];
int dist[110][110];
queue<pi> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            dist[i][j] = -1;
        }
    }
    dist[1][1] = 1;
    q.push({1,1});
    while(!q.empty()){
        int ni = q.front().f,nj = q.front().s;
        q.pop();
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = ni+i,jj = nj+j;
            if(ii < 1  || ii > n || jj < 1 || jj > m) continue;
            if(j==1 && (a[ni][nj] != 'R' && a[ni][nj] != 'B')) continue;
            if(i==1 && (a[ni][nj] != 'D' && a[ni][nj] != 'B')) continue;
            if(i==-1 && (a[ii][jj] != 'D' && a[ii][jj] != 'B')) continue;
            if(j==-1 && (a[ii][jj] != 'R' && a[ii][jj] != 'B')) continue;
            if(dist[ni][nj]+1>dist[ii][jj] && dist[ii][jj]!=-1) continue;
            if(dist[ni][nj]+1 == dist[ii][jj]){
                cout << dist[ii][jj] << '\n' << ii << ' ' << jj;
                return 0;
            }
            dist[ii][jj] = dist[ni][nj]+1;
            q.push({ii,jj});
        }
    }
    return 0;
}
