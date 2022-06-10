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
struct A{
    int i,j,d;
};
const int N = 20;
char a[N][N];
int visited[N][N];
queue<A> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == '@'){
                q.push({i,j});
                visited[i][j] = 1;
            }
            else if(a[i][j] == '#') visited[i][j] = 1;
        }
    }
    while(sz(q)){
        int ni = q.front().i,nj = q.front().j,d = q.front().d;
        q.pop();
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = ni+i,jj = nj+j;
            if(ii < 1 || ii > n || jj < 1 || jj > m){
                cout << d;
                return 0;
            }
            if(visited[ii][jj]) continue;
            visited[ii][jj] = 1;
            q.push({ii,jj,d+1});
        }
    }
    cout << -1;
    return 0;
}
