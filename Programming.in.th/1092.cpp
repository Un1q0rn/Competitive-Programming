#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> pa,a;
int fr(int i){
    if(pa[i] == i) return i;
    else return pa[i]=fr(pa[i]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,q;cin >> n >> q;
    a.resize(n+1);
    pa.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        pa[i]=i;
    }
    while(q--){
        int x,y;cin >> x >> y;
        int fx = fr(x);
        int fy = fr(y);
        if(fx == fy){
            cout << -1 << '\n';
            continue;
        }
        if(a[fx] > a[fy]){
            pa[fy] = fx;
            a[fx] += a[fy]/2;
            cout << fx << '\n';
        }
        else if(a[fx] < a[fy]){
            pa[fx] = fy;
            a[fy] += a[fx]/2;
            cout << fy << '\n';
        }
        else{
            if(fx > fy){
                pa[fx] = fy;
                a[fy] += a[fx]/2;
                cout << fy << '\n';
            }
            else{
                pa[fy] = fx;
                a[fx] += a[fy]/2;
                cout << fx << '\n';
            }
        }
    }
    return 0;
}
