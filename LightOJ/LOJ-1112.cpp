#include <bits/stdc++.h>
using namespace std;
 
#define ull unsigned long long
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)


int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    int c = t;
    while(t--){
        cout << "Case " << c-t << ":\n";
        int n,q;cin >> n >> q;
        vector<int> a(n);
        auto upd = [&](int i,int v){
            i++;
            while(i<=n){
                a[i] += v;
                i += i & -i;
            }
        };
        auto qry = [&](int i){
            i++;
            int res = 0;
            while(i>0){
                res += a[i];
                i -= i & -i;
            }
            return res;
        };
        for(int i=0;i<n;i++){
            int x;cin >> x;
            upd(i,x);
        }
        while(q--){
            int o;cin >> o;
            if(o == 2){
                int i,v;cin >> i >> v;
                upd(i,v);
            }
            else if(o == 3){
                int i,j;cin >> i >> j;
                cout << qry(j) - qry(i-1) << '\n';
            }
            else{
                int i;cin >> i;
                int v = qry(i) - qry(i-1);
                cout << v << '\n';
                upd(i,-v);
            }
        }
    }
    
    return 0;
}
