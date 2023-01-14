#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
ll gcd(ll a,ll b){
    return b == 0 ? a:gcd(b,a%b);
}
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n,x;cin >> n >> x;
    vector<int> a(n);
    vector<pair<int,int>> dp(x+1);
    for(auto &e:a) cin >> e;
    dp[0] = {1,0};
    for(int i=0;i<=x;i++){
        for(int j=0;j<n;j++){
            if(i-a[j] >= 0 && dp[i-a[j]].first){
                dp[i].first = 1;
                if(dp[i].second == 0) dp[i].second = dp[i-a[j]].second+1;
                else dp[i].second = min(dp[i].second,dp[i-a[j]].second+1);
            }
        }
    }
    cout << (dp[x].first ? dp[x].second:-1);
    return 0;
}
