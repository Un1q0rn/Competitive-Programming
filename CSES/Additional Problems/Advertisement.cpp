#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x),end(x)
#define pb push_back
#define sz(x) (int)x.size()
#define s second
#define f first
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<ll> a(n);
    for(auto &e:a) cin >> e;
    stack<ll> st;
    vector<ll> ans(n);
    for(int i=0;i<n;i++){
        while(sz(st) && a[st.top()] >= a[i]) st.pop();
        int len = i-(sz(st) ? st.top() : -1);
        ans[i] += a[i]*len;
        st.push(i);
    }
    while(sz(st)) st.pop();
    for(int i=n-1;i>=0;i--){
        while(sz(st) && a[st.top()] >= a[i]) st.pop();
        int len = (sz(st) ? st.top() : n) - i;
        ans[i] += a[i]*(len-1);
        st.push(i);
    }
    ll mx = 0;
    for(auto e:ans) mx = max(mx,e);
    cout << mx;
    return 0;
}

