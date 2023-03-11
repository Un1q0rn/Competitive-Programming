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
const int N = 5e2+10;
int dp[N][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;cin >> s;
    int n = sz(s);
    for(int j=0;j<n;j++){
        for(int i=0;i<n-j;i++){
            dp[i][i+j] = dp[i+1][i+j]+1;
            for(int k=i+1;k<=i+j;k++){
                if(s[i] != s[k]) continue;
                if(s[i])dp[i][i+j] = min(dp[i][i+j],dp[i+1][k-1]+dp[k+1][i+j]);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}
