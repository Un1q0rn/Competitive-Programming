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
    int n,k;cin >> n >> k;
    vector<ll> a(n);
    for(auto &e:a) cin >> e;
    sort(all(a));
    deque<int> dq;
    for(int i=0;i<n-k-1;i++){
        while(sz(dq) && a[i + 1] - a[i] < a[dq.back() + 1] - a[dq.back()]) dq.pop_back();
        dq.push_back(i);
    }
    ll ans = a[n-k-1] - a[0] + a[dq.front() + 1] - a[dq.front()];
    for(int i=n-k-1;i<n - 1;i++){
        if(sz(dq) && dq.front() <= i - k) dq.pop_front();
        while(sz(dq) && a[i + 1] - a[i] <= a[dq.back() + 1] - a[dq.back()]) dq.pop_back();
        dq.push_back(i);
        ans = min(ans,a[i] - a[i - (n - k) + 1] + a[dq.front() + 1] - a[dq.front()]);
    }
    cout << ans;
    return 0;
}
