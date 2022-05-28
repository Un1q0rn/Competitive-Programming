#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int N = 5e5+10;
const ll INF = 1e18;
ll shigh[N],shole[N],mnh=INF;
vector<pi> a;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    a.resize(n);
    for(int i=0;i<n;i++) {
        cin >> a[i].second;
        mnh = min(a[i].second,mnh);
    }
    for(int i=0;i<n;i++){
        cin >> a[i].first;
    }
    sort(all(a));
    for(int i=0;i<n;i++){
        if(i)shigh[i] = shigh[i-1]+a[i].second;
        else shigh[i] = a[i].second;
        if(i)shole[i] = shole[i-1]+a[i].first;
        else shole[i] = a[i].first;
    }
    ll ans1 = 0,ans2 = INF;
    for(int i=0;i<n && a[i].first <= mnh;i++){
        ll tmp1 = (shole[i]-a[i].first)+(shigh[i]-a[i].second)-(a[i].first*i);
        ll tmp2 = (shole[n-1]-shole[i])-(a[i].first*(n-i-1));
        ll res = tmp1+tmp2;
        if(res < ans2){
            ans2 = res;
            ans1 = a[i].first;
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}

