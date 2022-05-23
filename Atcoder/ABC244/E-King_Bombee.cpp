#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int M = 998244353;
const int N = 2e3+10;
ll dp[N][N][2];
int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k,s,t,x;cin >> n >> m >> k >> s >> t >> x;
    vector<pi> edge(m);
    for(auto &[u,v] : edge){
        cin >> u >> v;
    }
    dp[0][s][0] = 1;
    for(int i=0;i<k;i++){
        for(auto [u,v]:edge){
            for(auto j:{0,1}){ 
                dp[i+1][v][j^(v==x)] += dp[i][u][j];
                dp[i+1][u][j^(u==x)] += dp[i][v][j];
                dp[i+1][v][j^(v==x)] %= M;
                dp[i+1][u][j^(u==x)] %= M;
            }        
        }
    }
    cout << dp[k][t][0]%M;
    return 0;
}
