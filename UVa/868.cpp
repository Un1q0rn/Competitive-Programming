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
    return b == 0 ? a:gcd(b,a%b);
}
int a[105][105],vis[105][105];
int aj,n,m,flag;

void dfs(int ni,int nj,int p,int q){
    if(ni < 1 || ni > n || nj < 1 || nj > m){
        return ;
    }
    if(a[ni][nj] != p){
        return ;
    }
    if(vis[ni][nj]){
        return ;
    }
    vis[ni][nj] = 1;
    if(ni == n){
        aj = min(aj,nj);
        flag = 1;
        return ;
    }
    if(p == q) p = 0,q++;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = ni+i,jj = nj+j;
            dfs(ii,jj,p+1,q);
        }
    }
    vis[ni][nj] = 0;
}
void solve(){
    aj = 1e9,flag = 0;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }
    }
    int i;
    for(i=1;i<=m;i++){
        dfs(1,i,1,1);
        if(flag) break;
    }
    cout << 1 << ' ' << i << '\n' << n << ' ' << aj << '\n';
}  


bool multi = true;

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
        if(t) cout << '\n';
    }
    return 0;
}
