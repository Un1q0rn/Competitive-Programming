#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> sq(n+1);
    vector<vector<int>> fac(n+1);
    for(int i=1;i*i<=n;i++) sq[i*i] = 1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            fac[j].pb(i);
        }
    }
    vector<int> cnt(n+1);
    for(int i=1;i<=n;i++){
        int f=0;
        for(auto x:fac[i]){
            if(sq[x]) f=x;
        }
        cnt[i/f]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans+=cnt[i]*cnt[i];
    cout << ans;
    return 0;
}

