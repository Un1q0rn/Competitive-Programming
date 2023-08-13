#include <bits/stdc++.h> 
using namespace std; 

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n;cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    int q;cin >> q;
    while(q--){
        int x;cin >> x;
        auto it1 = lower_bound(a.begin(),a.end(),x);
        if(it1 == a.begin()) cout << "X ";
        else{
            cout << *(it1-1)<< ' ';
        }
        auto it2 = upper_bound(a.begin(),a.end(),x);
        if(it2 == a.end()) cout << "X\n";
        else{
            cout << *it2 << '\n';
        }
    }
    return 0; 
}
