#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    set<string> s;
    int n;cin >> n;
    for(int i=0;i<n;i++){
        string a;cin >> a;
        s.insert(a);
    }
    for(auto it=s.begin();it!=s.end();it++){
        cout << *it << "\n";
    }
    return 0;
}
