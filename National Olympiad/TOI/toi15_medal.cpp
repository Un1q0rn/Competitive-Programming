#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define pb push_back

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<ll> a(n),b(n);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),greater<ll>());
    ll mn=INT_MAX,mx=INT_MIN;
    queue<ll> ans;
    for(int i=0;i<n;i++){
        ll sum = a[i]+b[i];
        mn = min(mn,sum);
        mx = max(mx,sum);
    }
    cout << mx-mn;
    return 0;
}
