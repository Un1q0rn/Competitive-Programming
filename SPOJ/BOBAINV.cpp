#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

const int N = 5e3+100;
ll dp[N][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n; 
    vector<int> a(n+2);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i] > a[j] && i < j){
                dp[i][j]++;
            }
            dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
    int q;cin >> q;
    while(q--){
        int l,r;cin >> l >> r;
        cout << dp[r][r]-dp[l-1][r] << '\n';
    }
    return 0;
}
