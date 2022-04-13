#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,q;cin >> n >> m >> q;
    set<int> s;
    while(m--){
        int l,r;cin >> l >> r;
        if(s.find(l) == s.end()){
            s.insert(l);
        }
        else s.erase(l);
        if(s.find(l+r) == s.end()){
            s.insert(l+r);
        }
        else s.erase(l+r);
    }
    s.insert(1);
    s.insert(n+1);
    while(q--){
        int n;cin >> n;
        auto l = s.upper_bound(n);
        auto r = s.lower_bound(n);
        if(*r==*l) r--;
        cout << *l-*r << '\n';
    }
    return 0;
}
