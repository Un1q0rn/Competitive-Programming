#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const int N = 1.5*1e5+10;
const int INF = 1e9;
const int permute[6][3]{{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
int a[3][N],dp[3][N],n;
int solve(int now,int p,int k){
    if((now == n-1 && p != 2) || p > 2) return INF;
    if(dp[p][now] != -1) return dp[p][now];
    int res = min(solve(now+1,p,k),solve(now+1,p+1,k));
    dp[p][now] = res + a[permute[k][p]][now];
    return dp[p][now];
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    int ans = INF;
    for(int i=0;i<6;i++){
        memset(dp,-1,sizeof dp);
        for(int j=0;j<3;j++){
            dp[j][n-1] = a[permute[i][j]][n-1];
        }
        int res = solve(0,0,i);
        ans = min(ans,res);
    }
    cout << ans;
    return 0;
}
