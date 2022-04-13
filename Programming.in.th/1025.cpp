#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;cin >> q;
    ll ans=1;
    for(int i=0;i<q;i++){
        ll n;cin >> n;
        ans = lcm(ans,n);
    }
    cout << ans;
    return 0;
}
