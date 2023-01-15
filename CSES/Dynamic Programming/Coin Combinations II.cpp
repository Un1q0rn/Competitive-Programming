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
const int MOD = 1e9+7;
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n,x;cin >> n >> x;
    vector<int> a(n);
    vector<int> dp(x+1);
    for(auto &e:a) cin >> e;
    dp[0] = 1;
    for(int j=0;j<n;j++){
        for(int i=0;i<=x;i++){
            if(i-a[j] >= 0) dp[i]+=dp[i-a[j]];
            dp[i]%=MOD;
        }
    }
    cout << dp[x];
    return 0;
}
