#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

const int N = 1e3+100;
int isflood[N][N],visited[N][N];
char a[N][N];
vector<pi> house;
queue<pi> q;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int r,c;cin >> r >> c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin >> a[i][j];
            if(a[i][j] == 'X') house.pb({i,j});
        }
    }
    isflood[1][1] = 1;
    q.push({1,1});
    while(!q.empty()){
        int ni = q.front().first,nj = q.front().second;
        q.pop();
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = ni+i,jj = nj+j;
            if(ii < 1 || ii > r || jj < 1 || jj > c) continue;
            if(a[ii][jj] == 'X') continue;
            if(isflood[ii][jj]) continue;
            isflood[ii][jj] = 1;
            q.push({ii,jj});
        }
    }
    int ans = 0;
    for(auto x:house){
        int hi = x.first,hj = x.second,cnt = 0;
        visited[hi][hj] = 1;
        q.push({hi,hj});
        while(!q.empty()){
            int ni = q.front().first,nj = q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
                if(abs(i) == abs(j)) continue;
                int ii = ni+i,jj = nj+j;
                if(a[ii][jj] == '.') {
                    if(isflood[ii][jj]) cnt++;
                    continue;
                }
                if(visited[ii][jj]) continue;
                visited[ii][jj] = 1;
                q.push({ii,jj});
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans << '\n';
    return 0;
}
