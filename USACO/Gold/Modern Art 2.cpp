#include <bits/stdc++.h> 
using namespace std;

#define vi(x)  vector<x>
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define pb push_back
#define setdecimal(x) cout << fixed << setprecision(x)

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define ll long long int

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0); // see /general/fast-io
    if (sz(name)) {
        freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("art2");
    int n;cin >> n;
    vector<int> a(n),fst(n + 1,n + 10),lst(n + 1,-1);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(a[i] != 0){
            fst[a[i]] = min(fst[a[i]],i);
            lst[a[i]] = max(lst[a[i]],i);
        }
    }

    int ans = -1;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!a[i]) continue;
        if(i == fst[a[i]]){
            if(fst[a[i]] == lst[a[i]]){
                ans = max(ans,sz(st) + 1);
            }
            else{
                st.push(a[i]);
            }
        }
        else if(i == lst[a[i]]){
            if(st.top() == a[i]){
                ans = max(ans,sz(st));
                st.pop();
            }
            else{
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}
