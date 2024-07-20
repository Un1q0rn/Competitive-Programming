#include <bits/stdc++.h>
using namespace std;
 
#define ld long double 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> cnt(1e6 + 10),a(n);
    for(auto &e:a) cin >> e;
    int ans = 0;
    for(auto x:a){
        for(int i=1;i * i <= x;i++){
            if(x % i) continue;
            cnt[i]++;
            if(i * i != x) cnt[x / i]++;
            if(cnt[i] >= 2) ans = max(ans,i);
            if(cnt[x / i] >= 2) ans = max(ans,x / i);
        }
    }
    cout << ans;
    return 0;
}
