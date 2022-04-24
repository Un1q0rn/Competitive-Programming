#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll n,k;cin >> n >> k;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    ll l=1,r=1000000LL * k,mid;
    while(l<r){
        mid = (l+r)/2;
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum+=(mid/a[i]);
        }
        if(sum >= k){
            r = mid;
        }
        else l = mid+1;
    }
    cout << l;
    return 0;
}
