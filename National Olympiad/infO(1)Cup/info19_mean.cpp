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
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<vector<int>> dp(n,vector<int>(n));
    for(int i=0;i<n;i++){
        cin >> dp[i][i];
    }
    for(int j=1;j<n;j++){
        for(int i=0;i<n-j;i++){
            for(int k=i;k<i+j;k++){
                dp[i][i+j] = max(dp[i][i+j],(dp[i][k]+dp[k+1][i+j])>>1);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}
