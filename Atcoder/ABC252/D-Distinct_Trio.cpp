#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int N = 2e5+10;
ll dp[N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> a(n);
    for(auto &e:a){
        cin >> e;
        dp[e]++;
    }
    for(int i=1;i<N;i++){
        dp[i]+=dp[i-1];
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans+=(dp[a[i]-1])*(n-dp[a[i]]);
    }
    cout << ans;
    return 0;
}
