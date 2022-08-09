#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long int
#define ll long long int 
#define ld long double
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const int MOD = 1073741824;
ll gcd(ll a,ll b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
char a[25][25];
int vis[25][25];
queue<pi> q;
int solve(){
    int n,m;cin >> m >> n;
    FOR(i,1,n){
        FOR(j,1,m){
            cin >> a[i][j];
            if(a[i][j] == '@'){
                q.push({i,j});
                vis[i][j] = 1;
            }
        }
    }
    int ans = 1;
    while(sz(q)){
        int ni = q.front().f,nj = q.front().s;
        q.pop();
        for(int i=-1;i<=1;i++) for(int j=-1;j<=1;j++){
            if(abs(i) == abs(j)) continue;
            int ii = ni+i,jj = nj+j;
            if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
            if(a[ii][jj] == '#' || vis[ii][jj]) continue;
            vis[ii][jj] = 1;
            a[ii][jj] = '#';
            q.push({ii,jj});
            ans++;
        }
    }
    memset(vis,0,sizeof vis);
    return ans;
}

bool multi = true;

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t = 1;
    if(multi) cin >> t;
    int c = 1;
    while(t--){
        cout << "Case " << c << ": " << solve() << '\n';
        c++;
    }
    return 0;
}
