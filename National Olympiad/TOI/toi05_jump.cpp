#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    int ans = 0;
    for(int i=0;i<n;i++){
        int a2 = upper_bound(a.begin(),a.end(),a[i]+k)-a.begin();
        ans = max(ans,a2-i-1);
    }
    cout << ans;
    return 0;
}
