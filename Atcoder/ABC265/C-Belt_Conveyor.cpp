#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define pf push_front
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

char grid[550][550];
int vis[550][550];
void solve(){
    int n,m;cin >> n >> m;
    FOR(i,1,n){
        FOR(j,1,m){
            cin >> grid[i][j];
        }
    }
    queue<pair<int,int>> q;
    vis[1][1] = 1;
    q.push({1,1});
    int ni,nj;
    while(sz(q)){
        ni = q.front().f,nj = q.front().s;
        q.pop();
        int ii=ni,jj=nj;
        if(grid[ni][nj] == 'U'){
            ii--;
        }
        if(grid[ni][nj] == 'D'){
            ii++;
        }
        if(grid[ni][nj] == 'L'){
            jj--;
        }
        if(grid[ni][nj] == 'R'){
            jj++;
        }
        if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
        if(vis[ii][jj]){
            cout << -1;
            return;
        }
        vis[ii][jj] = 1;
        q.push({ii,jj});
    }
    cout << ni << ' ' << nj;
} 

bool multi = false;

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
