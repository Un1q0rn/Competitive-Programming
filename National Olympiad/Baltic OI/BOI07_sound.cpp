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
    int n,m,c;cin >> n >> m >> c;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    multiset<int> s;
    for(int i=0;i<m;i++) s.insert(a[i]);
    int ch = 1;
    if(*s.rbegin() - *s.begin() <= c) {
        cout << 1 << '\n';
        ch = 0;
    }
    for(int i=m;i<n;i++){
        s.erase(s.find(a[i-m]));
        s.insert(a[i]);
        if(*s.rbegin() - *s.begin() <= c) {
            cout << i-m+2 << '\n';
            ch = 0;
        }
    }
    if(ch) cout << "NONE";
    return 0;
}

