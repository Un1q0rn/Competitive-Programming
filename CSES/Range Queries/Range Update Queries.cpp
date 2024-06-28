#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

const int N = 2e5;
ll a[N+10],sum[N+10];
int n,q;

void upd(int i,int v){
    while(i<=n){
        sum[i] += v;
        i += i & -i;
    }
}

void add(int l,int r,int v){
    upd(l,v);
    upd(r+1,-v);
}

ll qry(int i){
    ll res = 0;
    while(i>0){
        res += sum[i];
        i -= i & -i;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    while(q--){
        int t;cin >> t;
        if(t == 1){
            int l,r,v;cin >> l >> r >> v;
            add(l,r,v);
        }
        else{
            int k;cin >> k;
            cout << a[k] + qry(k) << '\n';
        }
    }
    return 0;
}
