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
const int N = 2e3+100;
char a[N][N];
queue<pi> q;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<pi> pos;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == '1'){
                pos.pb({i,j});
            }
        }
    }
    int ans = 0;
    for(auto p:pos){
        if(a[p.f][p.s] == '0') continue;
        q.push({p.f,p.s});
        a[p.f][p.s] = '0';
        while(!q.empty()){
            int ni = q.front().f,nj = q.front().s;
            q.pop();
            for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
                if(i == 0 && j == 0) continue;
                int ii = ni+i,jj = nj+j;
                if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
                if(a[ii][jj] == '0') continue;
                a[ii][jj] = '0';
                q.push({ii,jj});
            }
        }
        ans++;
    }
    cout << ans;
    return 0;
}
