#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back

const int N = 55;
vector<vector<int>> a;
int dist[N][N],mark[N][N],dist2[N][N],mark2[N][N];
queue<pi> q1,q2;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int r,c,si,sj,di,dj,ans=INT_MAX;
    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char c;cin >> c;
            if(c == 'D'){
                di = i,dj = j;
                mark[i][j] = 1;
                mark2[i][j] = 1;
            }
            if(c == 'S'){
                si = i,sj = j;
                mark[i][j] = 1;
                mark2[i][j] = 1;
                q2.push({i,j});
            }
            if(c == 'X'){
                mark[i][j] = 1;
                mark2[i][j] = 1;
            }
            if(c == '*'){
                q1.push({i,j});
                mark[i][j] = 1;
                mark2[i][j] = 1;
            }
        }
    }
    while(!q1.empty()){
        int ni = q1.front().first,nj = q1.front().second,ii,jj;
        q1.pop();
        mark[ni][nj] = 1;
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(i == j || i+j == 0) continue;
            ii = ni+i,jj = nj+j;
            if(ii < 0 || ii > r-1 || jj < 0 || jj > c-1) continue;
            if(mark[ii][jj]) continue;
            q1.push({ii,jj});
            mark[ii][jj] = 1;
            dist[ii][jj] = dist[ni][nj]+1;
        }
    }
    while(!q2.empty()){
        int ni = q2.front().first,nj = q2.front().second,ii,jj;
        q2.pop();
        mark2[ni][nj] = 1;
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(i == j || i+j == 0) continue;
            ii = ni+i,jj = nj+j;
            if(ii < 0 || ii > r-1 || jj < 0 || jj > c-1) continue;
            if(mark2[ii][jj]) continue;
            q2.push({ii,jj});
            mark2[ii][jj] = 1;
            dist2[ii][jj] = dist2[ni][nj]+1;
        }
    }
    int ii,jj;
    for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
        if(i == j || i+j == 0) continue;
        ii = di+i,jj = dj+j;
        if(ii < 0 || ii > r-1 || jj < 0 || jj > c-1) continue;
        if(ii == si && jj == sj){
            cout << 1;
            return 0;
        }
        if((dist2[ii][jj] < dist[ii][jj] && dist2[ii][jj] != 0) || (dist[ii][jj] == 0 && dist2[ii][jj] > 0)){
            ans = min(ans,dist2[ii][jj]+1);
        }
    }
    if(ans != INT_MAX) cout << ans;
    else cout << "KAKTUS";
    return 0;
}
