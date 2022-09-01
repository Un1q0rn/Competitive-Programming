#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define pf push_front
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long 

const int N = 4e3+10;
char a[N][N];
int n,m,dis[N][N];
deque<pair<int,int>> dq;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    FOR(i,1,n){
        FOR(j,1,m){
            cin >> a[i][j];
        }
    }
    dq.pb({1,1});
    dis[1][1] = 1;
    int ans = 1;
    while(sz(dq)){
        int ni = dq.front().f,nj = dq.front().s;
        dq.pop_front();
        ans = max(ans,dis[ni][nj]);
        FOR(i,-1,1) FOR(j,-1,1) {
            if(abs(i) == abs(j)) continue;
            int ii = ni+i,jj = nj+j;
            if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
            if(a[ii][jj] == '.') continue;
            if(dis[ii][jj]) continue;
            if(a[ii][jj] == a[ni][nj]){
                dis[ii][jj] = dis[ni][nj];
                dq.pf({ii,jj});
            }
            else{
                dis[ii][jj] = dis[ni][nj]+1;
                dq.pb({ii,jj});
            }
            
        }
    }
    cout << ans;
    return 0;
}
