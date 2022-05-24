#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int N = 610;
int dp[N][N],a[N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    for(int sz=1;sz<n;sz++){
        for(int i=1;i+sz<=n;i++){
            int j = i+sz;
            for(int k=i;k<j;k++){
                int l = a[k]-a[i-1],r=a[j]-a[k];
                dp[i][j] = max(dp[i][j],2*min(l,r)+max(l,r)+dp[i][k]+dp[k+1][j]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
