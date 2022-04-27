#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

const int N = 1e6+10;
const ll MOD = 1e9+7;
ll dp[N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i>=j) dp[i]+=dp[i-j];
        }
        dp[i]%=MOD;
    }
    cout << dp[n] << '\n';
    return 0;
}
