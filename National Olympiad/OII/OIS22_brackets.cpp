#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
#define sz(x) (int)x.size()
#define all(x) begin(x),end(x)

void solve(){
    int n,k;cin >> n >> k;
    stack<int> st;
    while(n--){
        int p;cin >> p;
        if(sz(st) && st.top() == p) st.pop();
        else st.push(p);
    }
    if(!sz(st)) cout << 1 << '\n';
    else cout << 0 << '\n';
}
 
int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
} 
 
