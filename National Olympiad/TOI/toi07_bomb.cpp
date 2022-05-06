#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
struct A{
    ll x,y;
    bool operator < (const A&o) const{
        if(x!=o.x)  return x>o.x;
        return y<o.y;
    }
};
vector<A> a;
struct B{
    ll x,y;
    bool operator < (const B&o) const{
        if(x!=o.x)  return x<o.x;
        return y<o.y;
    }
};
vector<B> b;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    for(int i=0;i<n;i++){
        ll x,y;cin >> x >> y;
        a.pb({x,y});
    }
    sort(all(a));
    ll mxy = a[0].y;
    for(int i=0;i<n;i++){
        if(mxy <= a[i].y){
            b.pb({a[i].x,a[i].y});
            mxy = a[i].y;
        }
    }
    sort(all(b));
    for(auto x:b) cout << x.x << ' ' << x.y << '\n';
    return 0;
}
