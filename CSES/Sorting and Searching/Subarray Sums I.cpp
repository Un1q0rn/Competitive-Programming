#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define pf push_front
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long 

int main() {
    cin.tie(0)->sync_with_stdio(0);
    ll n,x;cin >> n >> x;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    ll p1=0,p2=1,ans=0;
    while(p1 != p2 && p2 <= n){
        if(a[p2]-a[p1] < x) p2++;
        else if(a[p2]-a[p1] > x){
            p1++;
        }
        else{
            ans++;
            p2++;
        }
    }
    cout << ans;
    return 0;
}
