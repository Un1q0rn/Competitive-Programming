#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k,x,p;cin >> n >> k;
    vector<ll> dp((1<<k)+1,INT_MAX);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        cin >> x;
        int w=0;
        for(int j=0;j<k;j++){
            cin >> p;
            if(p){
                w |= (1<<j);
            }
        }
        for(int j=0;j<(1<<k);j++){
            dp[j|w] = min(dp[j|w],dp[j]+x);
        }
    }
    cout << dp[(1<<k)-1] << '\n';
    return 0;
}
