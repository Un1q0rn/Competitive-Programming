  #include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int a[200][200],dist1[200][200],dist2[200][200];
queue<pi> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int r,c,si,sj,ei,ej;cin >> r >> c >> si >> sj >> ei >> ej;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
        }
    }
    dist1[si][sj] = 1;
    q.push({si,sj});
    while(!q.empty()){
        int ni = q.front().f,nj = q.front().s;
        q.pop();
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = i+ni,jj = j+nj;
            if(ii < 1  || ii > r || jj < 1 || jj > c) continue;
            if(dist1[ii][jj]) continue;
            if(a[ii][jj]){
                q.push({ii,jj});
            }
            dist1[ii][jj] = dist1[ni][nj]+1;
        }
    }
    int ans = INT_MAX,cnt = 0;
    dist2[ei][ej] = 1;
    q.push({ei,ej});
    while(!q.empty()){
        int ni = q.front().f,nj = q.front().s;
        q.pop();
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = i+ni,jj = j+nj;
            if(ii < 1 || ii > r || jj < 1 || jj > c) continue;
            if(dist2[ii][jj]) continue;
            if(a[ii][jj]){
                q.push({ii,jj});
            }
            dist2[ii][jj] = dist2[ni][nj] + 1;
            if(dist2[ii][jj] && dist1[ii][jj]){
                cnt++;
                ans = min(ans,dist2[ii][jj]+dist1[ii][jj]-1);
            }
        }
    }
    cout << cnt << '\n' << ans;
    return 0;
}
