#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define pi pair<ll,ll>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll l=0,r=1e18,mid;
    while(l<r){
        mid = (l+r)/2;
        stack<ll> st;
        for(int i=1;i<=n;i++){
            if(a[i] > mid){
                st.push(a[i]);
            }
        }
        int ch = 0;
        while(!st.empty()){
            ll t = st.top();
            st.pop();
            if(st.top() == t){
                st.pop();
            }
            else{
                ch = 1;
                break;
            }
        }
        if(ch) l = mid+1;
        else r = mid;
    }
    cout << l << '\n';
    return 0;
}
