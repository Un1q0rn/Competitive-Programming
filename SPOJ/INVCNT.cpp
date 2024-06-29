#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        vector<ll> a(n),v,bit(n+2); 
        for(auto &e:a) cin >> e;
        map<ll,int> idx;
        v = a;
        sort(all(v));
        for(int i=0;i<n;i++){
            idx[v[i]] = i+1;
        }
        for(int i=0;i<n;i++){
            a[i] = idx[a[i]];
        }
        auto upd = [&](int i,int v){
            while(i <= n){
                bit[i] += v;
                i += i & -i;
            }
        };
        auto qry = [&](int i){
            ll res = 0;
            while(i > 0){
                res += bit[i];
                i -= i & -i;
            }
            return res;
        };
        ll ans = 0;
        for(int i=n-1;i>=0;i--){
            ans += qry(a[i]);
            upd(a[i],1);
        }
        cout << ans << '\n';
    }
    return 0;
}
