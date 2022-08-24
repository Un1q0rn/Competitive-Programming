#include <bits/stdc++.h> 
using namespace std; 
#define ll long long int 
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
int main(){
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n,q;cin >> n >> q;
    vi(ll) a(n);
    for(auto &e:a) cin >> e;
    vi(ll) left,right,l(n),r(n);
    FOR(i,0,n-1){
        int pos = lower_bound(all(left),a[i])-left.begin();
        if(pos == sz(left)){
            left.pb(a[i]);
        }
        else left[pos] = a[i];
        l[i] = pos;
    }
    reverse(all(a));
    FOR(i,0,n-1){
        int pos = lower_bound(all(right),a[i])-right.begin();
        if(pos == sz(right)){
            right.pb(a[i]);
        }
        else right[pos] = a[i];
        r[i] = pos;
    }
    while(q--){
        int x;cin >> x;
        cout << min(l[x],r[n-x-1]) << '\n';
    }
    return 0;
}
