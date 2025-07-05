#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) begin(x),end(x)
#define sz(x) (int)x.size()
#define ul unsigned long long

int gcd(int a,int b) {return b == 0 ? a:gcd(b,a%b);}

struct BIT{
    vector<ll> f;
    BIT(int n) : f(n+2){}
    int n = sz(f) - 1;

    void upd(int i,int v){
        i++;
        while(i <= n){
            f[i]+=v;
            i += i & -i;
        }
    }

    ll qry(int i){
        i++;
        ll res = 0;
        while(i > 0){
            res += f[i];
            i -= i & -i;
        }
        return res;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n,q;cin >> n >> q;
    vector<int> x(n + 1);
    vector<pair<int,int>> query[n + 1];
    for(int i=1;i<=n;i++){
        cin >> x[i];
    }

    for(int i=0;i<q;i++){
        int a,b;cin >> a >> b;
        query[a].push_back({b,i});
    }

    BIT fw(n + 1);
    vector<int> ans(q);
    map<int,int> lst;
    for(int i = n; i >= 1;i--){
        fw.upd(i,1);
        if(lst.count(x[i]) != 0){
            fw.upd(lst[x[i]],-1);
        }
        lst[x[i]] = i;

        for(auto [b,j] : query[i]){
            ans[j] = fw.qry(b);
        }
    }

    for(auto e:ans) cout << e << '\n';
    return 0;
}
